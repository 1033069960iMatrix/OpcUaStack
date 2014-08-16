#ifndef __OpcUaStackCore_ExtensibleParameter_h__
#define __OpcUaStackCore_ExtensibleParameter_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	typedef std::map<OpcUaNodeId,ExtensibleParameterBase::BSPtr> ExtensibleParameterMap;

	class DLLEXPORT ExtensibleParameter : public  ObjectPool<ExtensibleParameter>
	{
	  public:
		static bool insertElement(OpcUaNodeId& opcUaNodeId, ExtensibleParameterBase::BSPtr epSPtr);
		static bool deleteElement(OpcUaNodeId& opcUaNodeId);
		static ExtensibleParameterBase::BSPtr findElement(OpcUaNodeId& opcUaNodeId);

		ExtensibleParameter(void);
		~ExtensibleParameter(void);

		template<typename T>
		  bool registerFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(buf, bufLen, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaNodeId& opcUaNodeId) {
			  ExtensibleParameterBase::BSPtr epSPtr(T::construct());
			  return ExtensibleParameter::insertElement(opcUaNodeId, epSPtr);
		  }

		bool deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(OpcUaNodeId& opcUaNodeId);

		OpcUaNodeId& parameterTypeId(void);
		bool exist(void);

		template<typename T>
		   typename T::SPtr parameter(void) {
			   if (epSPtr_.get() != NULL) {
				   return boost::static_pointer_cast<T>(epSPtr_);
			   }

			   epSPtr_ = findElement(parameterTypeId_);
			   if (epSPtr_.get() == NULL) {
				   typename T::SPtr epSPtr;
				   return epSPtr;
			   }

			   typename T::SPtr epSPtr = T::construct();
			   epSPtr_ = epSPtr;
			   return epSPtr;
		   }

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		static ExtensibleParameterMap extensibleParameterMap_;
		static bool init_;

		OpcUaNodeId parameterTypeId_;
		ExtensibleParameterBase::BSPtr epSPtr_;
	};

}

#endif
