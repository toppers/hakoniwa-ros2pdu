uint32 request_id
string service_name
string client_name
uint8 opcode  # 0=Request, 1=Cancel, 2=StatusPoll
int32 status_poll_interval_msec  # <=0: no poll, >0: periodic poll
