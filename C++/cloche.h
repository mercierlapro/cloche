//---------------------------------------------------------------------------

#ifndef clocheH
#define clocheH
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>


class cloche{

	private:
	TIdTCPClient * Client;                     //attributs

	public:

	void activation(unsigned char msg,TIdTCPClient * Client);
	void retourMarteau(TIdTCPClient * Client);                           //méthodes


};



#endif
