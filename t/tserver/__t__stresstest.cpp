#include <iostream>
#include <stdio.h>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <RCF/RCF.hpp>

#include "SK___t__servicedef.h"
#include "SK___t__clientproxy.h"
#include "iComm.h"

#include "dn.h"
#include "__t__client.h"

using namespace std;

using namespace Comm;


int RpcCallRcf()
{
	__T__Client client;
	string sResp;
	
	int ret = client.SKEcho( 10001, "stresstest", sResp);
	if(  ret !=COMM_OK)
	{
		LogDebug("ERR: ret %d errmsg %s", ret, client.GetLastErrMsg().c_str() );
		return ret;
	}

	return 0;
}

int main( int argc, char* argv[] )
{
	OpenLogfile("__t__stresstest", "/home/sspace/log/error" );
	if( argc < 3 )
	{
		printf("usage: %s processCount timeout\n", argv[0]);
		return -1;
	}
	printf("stresstest Rcf\n");
	return Comm::StressTestRun( atoi(argv[1]), RpcCallRcf, atoi(argv[2]));
}

/*
	��TIME_WAIT״̬�������ã�������ʹTIME_WAITռ�������ж˿ڣ�Ҳ����ܾ��µ���������ϰ�
	echo "1" > /proc/sys/net/ipv4/tcp_tw_reuse
	��TIME_WAIT������գ���Ҳ��֪�Ƕ�ã��۲�����һ����
	echo "1" > /proc/sys/net/ipv4/tcp_tw_recycle
*/
