#include <iostream>
//��������aris���ͷ�ļ�
#include <aris.hpp>
#include<string>


int main()
{
	std::cout << "start testing IO board" << std::endl;

	aris::control::EthercatMaster mst;	//����EtherCAT��վ����	

	//�ֶ����ô�վ����վ��˳�������ӵ�˳��һ�£���������xml��ʽ��������2��EtherCAT��վ����һ����վ��EtherCAT IO�忨���ڶ�����վ�������ŷ�������
	//�ο���վESI�ļ�����Ӵ�վ����EtherCAT IO�忨����
	//xml_str��,size�ĵ�λ��bit
	std::string xml_str =
		"<ethercatIO type=\"EthercatSlave\" phy_id=\"1\" product_code=\"0x00201\""
		" vendor_id=\"0x00000A09\" revision_num=\"0x64\" dc_assign_activate=\"0x00\">"
		"	<sm_pool type=\"SyncManagerPoolObject\">"
		"		<sm type=\"SyncManager\" is_tx=\"false\">"
		"			<index_1600 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1600\" is_tx=\"false\">"
		"				<Dout_0_7 index=\"0x7001\" subindex=\"0x01\" size=\"8\"/>"
		"			</index_1600>"
		"		</sm>"
		"		<sm type=\"SyncManager\" is_tx=\"false\">"
		"			<index_1601 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1601\" is_tx=\"false\">"
		"				<Dout_8_15 index=\"0x7001\" subindex=\"0x02\" size=\"8\"/>"
		"			</index_1601>"
		"		</sm>"
		"		<sm type=\"SyncManager\" is_tx=\"true\">"
		"			<index_1a00 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1a00\" is_tx=\"true\">"
		"				<Din_0_7 index=\"0x6001\" subindex=\"0x01\" size=\"8\"/>"
		"			</index_1a00>"
		"			<index_1a01 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1a01\" is_tx=\"true\">"
		"				<Din_8_15 index=\"0x6001\" subindex=\"0x02\" size=\"8\"/>"
		"			</index_1a01>"
		"		</sm>"
		"	</sm_pool>"
		"	<sdo_pool type=\"SdoPoolObject\" default_child_type=\"Sdo\">"
		"	</sdo_pool>"
		"</ethercatIO>";
	//���EtherCAT��վ�����У�
	//(1)��Ա����SlavePool()���ش�վ�����ã�����Ϊvector����ʵʱ����Ҫʹ��ecSlavePool()���ڷ�ʵʱ��ʹ��SlavePool()
	//(2)vector��������aris::control::EthercatSlave������add()ʵ�����vector��Ա
	//(3)����loadXmlStr()ʵ�ּ��ش�վ������Ϣxml_str
	mst.slavePool().add<aris::control::EthercatSlave>().loadXmlStr(xml_str);
	
	//�ο�ESI�ļ�����Ӵ�վ���������ŷ�������������
	xml_str =
		"<m_servo type=\"EthercatSlave\" phy_id=\"0\" product_code=\"0x60380007\""
		" vendor_id=\"0x0000066F\" revision_num=\"0x00010000\" dc_assign_activate=\"0x0300\">"
		"	<sm_pool type=\"SyncManagerPoolObject\">"
		"		<sm type=\"SyncManager\" is_tx=\"false\"/>"
		"		<sm type=\"SyncManager\" is_tx=\"true\"/>"
		"		<sm type=\"SyncManager\" is_tx=\"false\">"
		"			<index_1600 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1600\" is_tx=\"false\">"
		"				<control_word index=\"0x6040\" subindex=\"0x00\" size=\"16\"/>"
		"				<mode_of_operation index=\"0x6060\" subindex=\"0x00\" size=\"8\"/>"
		"				<target_pos index=\"0x607A\" subindex=\"0x00\" size=\"32\"/>"
		"				<target_vel index=\"0x60FF\" subindex=\"0x00\" size=\"32\"/>"
		"				<offset_vel index=\"0x60B1\" subindex=\"0x00\" size=\"32\"/>"
		"				<targer_tor index=\"0x6071\" subindex=\"0x00\" size=\"16\"/>"
		"				<offset_tor index=\"0x60B2\" subindex=\"0x00\" size=\"16\"/>"
		"			</index_1600>"
		"		</sm>"
		"		<sm type=\"SyncManager\" is_tx=\"true\">"
		"			<index_1a00 type=\"Pdo\" default_child_type=\"PdoEntry\" index=\"0x1A00\" is_tx=\"true\">"
		"				<status_word index=\"0x6041\" subindex=\"0x00\" size=\"16\"/>"
		"				<mode_of_display index=\"0x6061\" subindex=\"0x00\" size=\"8\"/>"
		"				<pos_actual_value index=\"0x6064\" subindex=\"0x00\" size=\"32\"/>"
		"				<vel_actual_value index=\"0x606c\" subindex=\"0x00\" size=\"32\"/>"
		"				<cur_actual_value index=\"0x6078\" subindex=\"0x00\" size=\"16\"/>"
		"			</index_1a00>"
		"		</sm>"
		"	</sm_pool>"
		"	<sdo_pool type=\"SdoPoolObject\" default_child_type=\"Sdo\">"
		"	</sdo_pool>"
		"</m_servo>";
	//���EtherCAT��վ�����У�
	//(1)��Ա����SlavePool()���ش�վ�����ã�����Ϊvector����ʵʱ����Ҫʹ��ecSlavePool()���ڷ�ʵʱ��ʹ��SlavePool()
	//(2)vector��������aris::control::EthercatSlave������add()ʵ�����vector��Ա
	//(3)����loadXmlStr()ʵ�ּ��ش�վ������Ϣxml_str
	mst.slavePool().add<aris::control::EthercatSlave>().loadXmlStr(xml_str);

	
	//�Զ�ɨ�衢���Ӵ�վ(Ĭ����ע�͵�mst.scan())����վ��˳����ʵ������������ͬ�������У��������˵�һ����վ���������������ڶ�����վ��EtherCAT IO�忨�����ʹ���Զ�ɨ��վģʽ��mst.ecSlavePool().at(0)��Ҫ�ĳ�mst.ecSlavePool().at(1);
	//mst.scan();
	
	//��ӡ��վɨ��Ĵ�վ����
	std::cout << "slave num:" << mst.slavePool().size() << std::endl;		

	//��վ����mst�ĳ�Ա����setControlStrategy()����һ��ʵʱ�̡߳����βμ��Ǳ����õ�ʵʱ��������ʵʱ����ÿ1ms������1��
	//�����ú�������ʵ����վ���վ֮������ݽ�������ӡ����log����(�����Զ���дIO�źţ�����ӡΪ��)
	mst.setControlStrategy([&]()
	{
		static int count{ 0 };
		static std::uint8_t value_dq{ 0x01 };
		static std::uint8_t value_di{ 0x00 };
		//
		if (++count % 1000 == 0)
		{
			//EtherCAT IO�忨�����ʵ�֡�����ơ�
			value_dq = value_dq << 1;
			if (value_dq == 0) value_dq = 0x01;

			//��Ա����mout()��ʵʱ�˴�ӡ�����ӿڣ���Ա����lout()��ʵʱ��log�����ӿ�
			mst.mout() << "count:" << std::dec << count << std::endl;
			mst.lout() << "count:" << std::dec << count << std::endl;

			//��Ա����ecSlavePool()������վvector����ʵʱ����Ҫʹ��ecSlavePool()���ڷ�ʵʱ��ʹ��SlavePool()��at(0)��ʾ��һ����վ����EtherCAT IO�忨
			mst.ecSlavePool().at(0).writePdo(0x7001, 0x02, &value_dq, 8);	//writePdo��д��������һ���β���index���ڶ����β���subindex���������β�дDO����ֵ�����ĸ��βα�ʾд������bit��
			mst.ecSlavePool().at(0).readPdo(0x6001, 0x01, &value_di, 8);	//readPdo�Ƕ���������һ���β���index���ڶ����β���subindex���������βζ�DI����ֵ�����ĸ��βα�ʾ��������bit��
		}
	});

	//����ʵʱ�߳�
	mst.start();

	//��ʵʱ�߳�˯��100����
	std::this_thread::sleep_for(std::chrono::seconds(100));

	//�ر�ʵʱ�߳�
	mst.stop();

	return 0;
}
