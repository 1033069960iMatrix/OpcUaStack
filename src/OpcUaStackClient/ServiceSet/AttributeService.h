/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT AttributeService
	: public OpcUaStackCore::Component
	{
	  public:
		typedef boost::shared_ptr<AttributeService> SPtr;

		AttributeService(OpcUaStackCore::IOThread* ioThread);
		~AttributeService(void);

		void setConfiguration(
			OpcUaStackCore::Component* componentSession
		);
		void componentSession(OpcUaStackCore::Component* componentSession);

		void syncSend(OpcUaStackCore::ServiceTransactionRead::SPtr serviceTransactionRead);
		void asyncSend(OpcUaStackCore::ServiceTransactionRead::SPtr serviceTransactionRead);
		void syncSend(OpcUaStackCore::ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void asyncSend(OpcUaStackCore::ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void syncSend(OpcUaStackCore::ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void asyncSend(OpcUaStackCore::ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void syncSend(OpcUaStackCore::ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);
		void asyncSend(OpcUaStackCore::ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		OpcUaStackCore::Component* componentSession_;
	};

}

#endif
