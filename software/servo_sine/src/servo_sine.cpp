#include<iostream>
//��������sris���ͷ�ļ�
#include<aris.hpp>

using namespace std;
//����aris���е�planģ��
using namespace aris::plan;
/*�������ص���һ����ָ�룬ָ��ָ��Controller,controller������������ָ��
    std::unique_ptr*/
auto createControllerRokaeXB4()->std::unique_ptr<aris::control::Controller>	
{
	/*����std::unique_ptrʵ��*/
	std::unique_ptr<aris::control::Controller> controller(new aris::control::EthercatController);
	/*����Ethercat��������xmal�ļ�
		phy_idָ�������ţ�������������˴������0�ŵ����xml����
		product_code��vendor_id�������ɿ�������ȡ
		min_pos��max_pos���� ���г��йأ�ǰ��С�ڵ�׵���Сλ��0mm����
		     �ߴ��ڵ�׵�����γ�100mm
		max_vel���ݵ�׵Ķת�ٺ��г������㣬��
		     3000��ת�٣�*4�����̣�/60/1000=0.2����λm/s��
		min_vel��max_vel��С��ȣ������෴
		max_acc���վ��鶨��Ϊ�ٶȵ�10��
		max_pos_following_error��max_vel_following_error�ɾ�������ȷ��
		home_posָ��׵ĳ�ʼλ�ã�����Ϊ0
		pos_factorָ������ƽ�1�׵�����£��������ĵ��źŸ�����ͨ����ѯ���
		     Ϊ23bit������ת��һȦ������µ�����Ĵ�����2^23=8388608���������
		     ��һ����Ҫת��250Ȧ����pos_factor=8388608*250=2097152000
		pos_offset��ָ����ڶϵ����������ĳ�ʼλ�þ���0���ƫ��*/
	std::string xml_str =
        "<m_servo_press type=\"EthercatMotion\" phy_id=\"0\" product_code=\"0x60380005\""
		" vendor_id=\"0x0000066F\" revision_num=\"0x00010000\" dc_assign_activate=\"0x0300\""
        " min_pos=\"-0.1\" max_pos=\"0.15\" max_vel=\"0.2\" min_vel=\"-0.2\""
		" max_acc=\"2.0\" min_acc=\"-2.0\" max_pos_following_error=\"0.005\" max_vel_following_error=\"0.005\""
        " home_pos=\"0\" pos_factor=\"2097152000\" pos_offset=\"0.00383346\">"
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
		"</m_servo_press>";
	controller->slavePool().add<aris::control::EthercatMotion>().loadXmlStr(xml_str);
	//����phy_i��ֵΪ1�����1�ŵ����xml����,����������ͬ��
	std::string xml_str1 =
        "<m_servo_press type=\"EthercatMotion\" phy_id=\"1\" product_code=\"0x60380005\""
        " vendor_id=\"0x0000066F\" revision_num=\"0x00010000\" dc_assign_activate=\"0x0300\""
        " min_pos=\"-0.1\" max_pos=\"0.15\" max_vel=\"0.2\" min_vel=\"-0.2\""
        " max_acc=\"2.0\" min_acc=\"-2.0\" max_pos_following_error=\"0.005\" max_vel_following_error=\"0.005\""
        " home_pos=\"0\" pos_factor=\"2097152000\" pos_offset=\"0.0032925\">"
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
		"</m_servo_press>";
	controller->slavePool().add<aris::control::EthercatMotion>().loadXmlStr(xml_str1);

	return controller;
};

//moveJS�е�s��ָsin����
//����ṹ�壬��Ӳ�������������ʱ��total_time������step_size
struct MoveJSParam
{
	int total_time;
	int left_time;
    double step_size;//
};

//�����࣬�м����࣬���м��������㷨
class MoveJS : public aris::plan::Plan
{
public:
	auto virtual prepairNrt(const std::map<std::string, std::string> &params, PlanTarget &target)->void
	{
        MoveJSParam p;
		//��total_time����ֵת��Ϊint���Ͳ���ֵ����p�еĲ���total_time
		p.total_time = std::stoi(params.at("total_time"));
		//��step_size����ֵת��Ϊdouble���Ͳ���ֵ����p�еĲ���step_size
        p.step_size=std::stod(params.at("step_size"));//
		p.left_time = 0;
		target.param = p;
        target.option =
                aris::plan::Plan::NOT_CHECK_POS_CONTINUOUS_SECOND_ORDER |
                aris::plan::Plan::NOT_CHECK_POS_CONTINUOUS_SECOND_ORDER_AT_START |
                aris::plan::Plan::NOT_CHECK_POS_FOLLOWING_ERROR |
                aris::plan::Plan::NOT_CHECK_VEL_FOLLOWING_ERROR |
                aris::plan::Plan::NOT_CHECK_VEL_CONTINUOUS_AT_START |
                aris::plan::Plan::NOT_CHECK_VEL_CONTINUOUS;
	}
	auto virtual executeRT(PlanTarget &target)->int
	{
        
        auto controller = target.controller;
        auto &p = std::any_cast<MoveJSParam&>(target.param);

        //p.total_time
		//��ӵ�׵���ʼλ�ò���beginpos[2]
        static double beginpos[2];
		//�������һ������ʱ������ĳ�ʼλ�ã�����ֵ��beginpos[2]
        if(target.count == 1)
        {
			//��ӡ������׵ĳ�ʼλ��beginpos[2]
            controller->mout()<<"mot1:" << controller->motionPool()[0].actualPos()<<std::endl;
            controller->mout()<<"mot2:" << controller->motionPool()[1].actualPos()<<std::endl;
			//��ȡ������׵ĳ�ʼλ�ã�����ֵ������
            beginpos[0] = controller->motionPool()[0].actualPos();
            beginpos[1] = controller->motionPool()[1].actualPos();
        }
		/*����������׵�sine�켣���߿��ƺ���,����ʱ��Ϊһ����������
		beginpos[0]����ļ����Ƕ�Ӧ�ŵ���ƽ�����Զ��λ��*/
        controller->motionPool()[0].setTargetPos(beginpos[0] - p.step_size*(1 - std::cos(1.0*target.count / p.total_time * 2 * aris::PI))) ; 
        controller->motionPool()[1].setTargetPos(beginpos[1] - p.step_size*(1 - std::cos(1.0*target.count / p.total_time * 2 * aris::PI))) ;

        return p.total_time - target.count;
	}
	auto virtual collectNrt(PlanTarget &target)->void {}
    explicit MoveJS(const std::string &name = "myplan"):Plan(name)
	{
		/*����滮������myplan��xml�ļ�
			����ʱ��total_time����Ϊ5000������ʵʱ��1ms����һ�Σ�������ʱ��Ϊ5s
			������step_size��ֵΪ0.045m���������ƶ�����Զ����Ϊ2*0.045=0.09
			�ڵ�׵��г�0.1֮��*/
		command().loadXmlStr(
			"<myplan>"
            "	<group type=\"GroupParam\">"
            "	    <total_time type=\"Param\" default=\"5000\"/>" //
            "       <step_size type=\"Param\" default=\"0.045\"/>"
            "   </group>"
            "</myplan>");
	}
};

auto createPlanRootRokaeXB4()->std::unique_ptr<aris::plan::PlanRoot>
{
	std::unique_ptr<aris::plan::PlanRoot> plan_root(new aris::plan::PlanRoot);

    plan_root->planPool().add<aris::plan::Enable>();
    plan_root->planPool().add<aris::plan::Disable>();
    plan_root->planPool().add<aris::plan::Mode>();
    plan_root->planPool().add<aris::plan::Recover>();
    plan_root->planPool().add<aris::plan::Sleep>();
    auto &rs = plan_root->planPool().add<aris::plan::Reset>();
	rs.command().findByName("group")->findByName("pos")->loadXmlStr("<pos default=\"{0.5,0.392523364485981,0.789915966386555,0.5,0.5,0.5,0.01}\" abbreviation=\"p\"/>");

    plan_root->planPool().add<aris::plan::MoveL>();
	plan_root->planPool().add<aris::plan::MoveJ>();
	plan_root->planPool().add<MoveJS>();
	plan_root->planPool().add<aris::plan::Show>();

	
	return plan_root;
}

int main(int argc, char *argv[])
{
	//����Ethercat��վ����
    aris::control::EthercatMaster mst;
	//�Զ�ɨ�裬���Ӵ�վ
    //mst.scan();
    std::cout<<mst.xmlString()<<std::endl;
	//cs�����Ա���������ã�aris��ͷ�ļ���server�������ռ䣬ControlServer�ǽṹ��
    auto&cs = aris::server::ControlServer::instance();
    cs.resetController(createControllerRokaeXB4().release());
    cs.resetPlanRoot(createPlanRootRokaeXB4().release());

    std::cout<<"start"<<std::endl;
	//�����߳�
	cs.start();
	//getline�ǽ������ֵ��ֵ��command_in
	for (std::string command_in; std::getline(std::cin, command_in);)
	{
		try
		{
			auto id = cs.executeCmd(aris::core::Msg(command_in));
			std::cout << "command id:" << id << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			//LOG_ERROR << e.what() << std::endl;
		}
	}

	char ch;
	std::cin >> ch;
}
