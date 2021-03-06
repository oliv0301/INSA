/* Protocol 6 (nonsequential receive) accepts frames out of order, but
 * passes packets to the network layer in order. Associated with each
 * outstanding frame is a timer. When the timer goes off, only that frame is
 * retransmitted, not all the outstanding frames.
 *
 * Written by Andrew S. Tanenbaum
 * Revised by Shivakant Mishra
 * Revised, 2010, by Stephen W. Turner
 */

#define MAX_SEQ 7
#define NR_BUFS ((MAX_SEQ + 1)/2)
typedef enum {frame_arrival, cksum_err, timeout, network_layer_ready, ack_timeout} event_type;
#include <stdlib.h>
#include <stdio.h>
#include "protocol.h"

static boolean between(seq_nr a, seq_nr b, seq_nr c)
{
  return ((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a));
}

static void send_frame(frame_kind fk, seq_nr frame_nr, seq_nr frame_expected, packet buffer[])
{
  frame s;
  s.kind = fk;

  if (fk == data)
    s.info = buffer[frame_nr % NR_BUFS];
  s.seq = frame_nr;
  s.ack = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);
  to_physical_layer(&s);
  if (fk == data)
    start_timer(frame_nr % NR_BUFS);
    
    
}

void protocol(void)
{
  seq_nr ack_expected;
  seq_nr next_frame_to_send;
  seq_nr frame_expected;
  seq_nr too_far;
  int i;
  frame r;
  packet out_buf[NR_BUFS];
  packet in_buf[NR_BUFS];
  boolean arrived[NR_BUFS];
  seq_nr nbuffered;
  event_type event;

  enable_network_layer();
  ack_expected = 0;
  next_frame_to_send = 0;
  frame_expected = 0;
  too_far = NR_BUFS;
  nbuffered = 0;

  for (i = 0; i < NR_BUFS; i++) arrived[i] = false;

  while (true) {
    wait_for_event(&event);

    switch(event) {

      case network_layer_ready:
        nbuffered = nbuffered + 1;
        from_network_layer(&out_buf[next_frame_to_send % NR_BUFS]);
        send_frame(data, next_frame_to_send, frame_expected, out_buf);
        inc(next_frame_to_send);
        break;

      case frame_arrival:
        from_physical_layer(&r);
        if (r.kind == data) {
          if (between(frame_expected, r.seq, too_far) && (arrived[r.seq%NR_BUFS]==false)) {
            arrived[r.seq % NR_BUFS] = true;
            in_buf[r.seq % NR_BUFS] = r.info;

            while (arrived[frame_expected % NR_BUFS]) {
           	 to_network_layer(&in_buf[frame_expected % NR_BUFS]);
             	 no_nak=true;
             	 arrived[frame_expected % NR_BUFS]=false;
             	 inc(frame_expected);	
             	 inc(too_far);
		 start_ack_timer(); 
            }
          }
        }

        while (between(ack_expected, r.ack, next_frame_to_send)) {
          nbuffered = nbuffered - 1;
          inc(ack_expected);
        }
        break;

     case cksum_err:
        break;

     case timeout:
        send_frame(data, get_timedout_seqnr(), frame_expected, out_buf);
        break;

     case ack_timeout:
        send_frame(ack,0,frame_expected, out_buf);
    }

    if (nbuffered < NR_BUFS)
      enable_network_layer();
    else
      disable_network_layer();
  }
}


main (int argc, char *argv[])
{
  int timeout_interval, pkt_loss, garbled, debug_flags;
  long event;
  int multiples;

  if (!parse_first_six_parameters(argc, argv, &event, &timeout_interval,
        &pkt_loss, &garbled, &debug_flags, &multiples)) {
    printf ("Usage: p events timeout loss cksum debug Datafile-flag\n");
    exit(1);
  }

  init_max_seqnr(MAX_SEQ + 1);
  printf("\n\n Simulating Protocol \n");
  start_simulator(protocol, protocol, event, timeout_interval, pkt_loss,
      garbled, debug_flags, multiples);
}

