/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h>

namespace OpcUaStackPubSub
{

	PubSubWriterGroupModel::PubSubWriterGroupModel(void)
	: PubSubState()
	, name_("")
	{
	}

	PubSubWriterGroupModel::~PubSubWriterGroupModel(void)
	{
	}

	void
	PubSubWriterGroupModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	PubSubWriterGroupModel::name(void)
	{
		return name_;
	}

}
