#ifndef PROCESS_DATA_H_
#define PROCESS_DATA_H_

void Process_Data(void);

extern short RxBuffer[];
extern short TxBuffer[];
extern short* RxPing;
extern short* RxPong;
extern short* TxPing;
extern short* TxPong;

#endif /* PROCESS_DATA_H_ */
