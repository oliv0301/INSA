/* Protocol 5 (pipelining) allows multiple outstanding frames. The sender
 * may transmit up to MAX_SEQ frames without waiting for an ack. In addition,
 * unlike the previous protocols, the network layer is not assumed to have
 * a new packet all the time. Instead, the network layer causes a
 * network_layer_ready event when there is a packet to send. 
 *
 * To compile: cc -o protocol5 p5.c simulator.o
 * To run: protocol5 events timeout  pct_loss  pct_cksum  debug_flags
 *
 * Written by Andrew S. Tanenbaum
 * Revised by Shivakant Mishra
 */

#define MAX_SEQ 7	/* should be 2^n - 1 */
typedef enum {frame_arrival, cksum_err, timeout, network_layer_ready} event_type;
#include "protocol.h"

static boolean between(seq_nr a, seq_nr b, seq_nr c)
{
/* Return true if (a <=b < c circularly; false otherwise. */
  if (((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a)))
        return(true);
    else
        return(false);
}

static void send_data(seq_nr frame_nr, seq_nr frame_expected, packet buffer[]) 
{
	frame s;

   	init_frame(&s);
    	s.kind = data;
    	s.info = buffer[frame_nr];
    	s.seq = frame_nr;	
    	s.ack = (frame_expected+MAX_SEQ)%(MAX_SEQ+1);
    	to_physical_layer(&s);/* transmition */
	start_timer(frame_nr); 
}

void protocol5(void)
{
  seq_nr next_frame_to_send;
  seq_nr ack_expected;
  seq_nr frame_expected;
  frame r;
  packet buffer[MAX_SEQ+1];
  int nbuffered;
  seq_nr i;
  event_type event;

  enable_network_layer();
  ack_expected = 0;
  next_frame_to_send = 0;
  frame_expected = 0;
  nbuffered = 0;
  while (true) {
     wait_for_event(&event);	/* four possibilities: see event_type above */

     switch(event) { 
        case network_layer_ready:	/* the network layer has a packet to send */
		from_network_layer(&buffer[next_frame_to_send]);
		nbuffered = nbuffered+1;
             	send_data(next_frame_to_send, frame_expected, buffer);	/* transmition */
		inc(next_frame_to_send);
                break;

        case frame_arrival:	/* a data or control frame has arrived */
		from_physical_layer(&r);
                if (r.seq == frame_expected){
                    to_network_layer(&r.info);	
                    inc(frame_expected);
                }

                while (between(ack_expected, r.ack, next_frame_to_send)){
                    nbuffered = nbuffered-1;
                    stop_timer(ack_expected);
                    inc(ack_expected);
		}
                break;

        case cksum_err: ;	/* just ignore bad frames */
                break;
  
        case timeout:	/* trouble; retransmit all outstanding frames */
  }
  if (nbuffered < MAX_SEQ)
          enable_network_layer();
      else
          disable_network_layer();

}

int main(int argc, char *argv[])
{
  int timeout_interval, pkt_loss, garbled, debug_flags;
  long event;

  if (!parse_first_five_parameters(argc, argv, &event, &timeout_interval,
                                   &pkt_loss, &garbled, &debug_flags))  {
    printf ("Usage: p5 events timeout loss cksum debug\n");
    exit(1);
  }

  printf("\n\n Simulating Protocol 5\n");
  start_simulator(protocol5, protocol5, event, timeout_interval, pkt_loss, garbled, debug_flags);
}


