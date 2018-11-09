#ifndef __PDU_LIMIT__ 
#define __PDU_LIMIT__

#define PDU_TYPE_DATA "D"
/*Question1:*/
typedef struct{
    char type;
    char lg[BUFSIZ];
}headerPDU;

typedef struct{
	char data[BUFSIZ];
}dataPDU;

typedef struct{
    headerPDU head;
	dataPDU data;
}messagePDU;

#endif
