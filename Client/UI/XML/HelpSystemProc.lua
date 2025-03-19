--2008.09.10 tavia
--帮助系统的函数处理---
-------变量的声明

--判断当前选定的是哪个功能 1：战士，2：斗士，3：祭师，4：法师
local func_select_flags=0;
--判断当前选定的是哪个1级子功能
local first_select_flags=0;
--判断当前选定的是哪个2级子功能
local second_select_flags=0;

local uiapi=UIAPI
local win = nil;
local container = nil;
local container1 = nil;
local cont1_text = nil;
local cont1_btn1 = nil;
local cont1_btn2 = nil;
local cont1_btn3 = nil;

local cont1_btn4 = nil;
local cont1_btn5 = nil;
local cont1_btn6 = nil;
local cont1_btn7 = nil;
local cont1_btn8 = nil;
local cont1_btn9 = nil;
local cont1_btn10 = nil;
local cont1_btn11 = nil;
local cont1_btn12 = nil;

local cont1_btn101 = nil;
local cont1_btn102 = nil;
local cont1_btn103 = nil;
local cont1_backfirstbtn = nil;
local cont1_backsecondbtn = nil;
local cont1_backfrontbtn = nil;
local cont1_temptext = nil;

HelpSystem_Color1 = {r=255,g=0,b=0,a=255};

--初始化各个控件
function HelpSystem_OnLoad()         
	win = uiapi:GetElement("HelpSystem");	
	container = win:GetChild("Container");
	container:GetChild(0):SetTexture("");
	container1 = win:GetChild("Container1");
	container1:GetChild(0):SetTexture("");
	cont1_text =container1:GetChild("Text");
	cont1_btn1 =container1:GetChild("Btn1");
	cont1_btn2 =container1:GetChild("Btn2");	
	cont1_btn3 =container1:GetChild("Btn3");

	cont1_btn4 =container1:GetChild("Btn4");
	cont1_btn5 =container1:GetChild("Btn5");	
	cont1_btn6 =container1:GetChild("Btn6");
	cont1_btn7 =container1:GetChild("Btn7");
	cont1_btn8 =container1:GetChild("Btn8");	
	cont1_btn9 =container1:GetChild("Btn9");
	cont1_btn10 =container1:GetChild("Btn10");
	cont1_btn11 =container1:GetChild("Btn11");	
	cont1_btn12 =container1:GetChild("Btn12");	
	
	cont1_btn101 =container1:GetChild("Btn101");
	cont1_btn102 =container1:GetChild("Btn102");	
	cont1_btn103 =container1:GetChild("Btn103");
	cont1_backfirstbtn =container1:GetChild("BackFirstBtn");	
	cont1_backsecondbtn =container1:GetChild("BackSecondBtn");	
	cont1_backfrontbtn =container1:GetChild("BackFrontBtn");
	cont1_temptext = container1:GetChild("TempText");	
	win:UpdateRenderBuffer();


	UIAPI:SetTextSelectColor(0,"HelpSystem_Color1",cont1_text);
	UIAPI:SetTextSelectKey(0,HSP_L0_1,cont1_text);

end
--设置帮助窗体是否可见
function HelpSystem_OnSetVisble()
	win:Visible(not win:IsVisible());
	if win:IsVisible() then
		win:Top();
	end
end
--纯文本的功能
--新手帮助
function HelpSystem_OnClickNewBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(0).static_text);
end
--人物属性
function HelpSystem_OnClickProfBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(1).static_text);
end
--任务
function HelpSystem_OnClickQuestBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(2).static_text);
end
--装备
function HelpSystem_OnClickEquipBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(3).static_text);
end
--交际
function HelpSystem_OnClickRelaBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(4).static_text);
end
--公会
function HelpSystem_OnClickConsBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(5).static_text);
	end
	--守护精灵
function HelpSystem_OnClickAutoBtn()
	HelpSystem_Initcontainer1();
	cont1_text:SetText(Get_HelpSystem_Cofig(6).static_text);
end
--战士
function HelpSystem_OnClickWarriorBtn()
	HelpSystem_Initcontainer1();
	
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_2);
	
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_3);
	
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_4);
	
	cont1_btn4:Visible(true);
	cont1_btn4:SetText(HSP_L0_5);
	
	cont1_btn5:Visible(true);
	cont1_btn5:SetText(HSP_L0_6);
	
	cont1_btn6:Visible(true);
	cont1_btn6:SetText(HSP_L0_7);
	
	cont1_btn7:Visible(true);
	cont1_btn7:SetText(HSP_L0_8);
	
	cont1_btn8:Visible(true);
	cont1_btn8:SetText(HSP_L0_9);
	
	cont1_btn9:Visible(true);
	cont1_btn9:SetText(HSP_L0_10);
	
	cont1_btn10:Visible(true);
	cont1_btn10:SetText(HSP_L0_11);
	
	container1:Auto();
	func_select_flags = 1;
end
--斗士
function HelpSystem_OnClickChampionBtn()
	HelpSystem_Initcontainer1();
	
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_12);
	
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_13);
	
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_14);
	
	cont1_btn4:Visible(true);
	cont1_btn4:SetText(HSP_L0_15);
	
	cont1_btn5:Visible(true);
	cont1_btn5:SetText(HSP_L0_16);
	
	cont1_btn6:Visible(true);
	cont1_btn6:SetText(HSP_L0_17);
	
	cont1_btn7:Visible(true);
	cont1_btn7:SetText(HSP_L0_18);
	
	cont1_btn8:Visible(true);
	cont1_btn8:SetText(HSP_L0_19);
	
	cont1_btn9:Visible(true);
	cont1_btn9:SetText(HSP_L0_20);
	
	cont1_btn10:Visible(true);
	cont1_btn10:SetText(HSP_L0_21);
	
	cont1_btn11:Visible(true);
	cont1_btn11:SetText(HSP_L0_22);
	
	container1:Auto();
	func_select_flags = 2;
end
--祭师
function HelpSystem_OnClickMgaeBtn()
	HelpSystem_Initcontainer1();
	
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_23);
	
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_24);
	
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_25);
	
	cont1_btn4:Visible(true);
	cont1_btn4:SetText(HSP_L0_26);
	
	cont1_btn5:Visible(true);
	cont1_btn5:SetText(HSP_L0_27);
	
	cont1_btn6:Visible(true);
	cont1_btn6:SetText(HSP_L0_28);
	
	cont1_btn7:Visible(true);
	cont1_btn7:SetText(HSP_L0_29);
	
	cont1_btn8:Visible(true);
	cont1_btn8:SetText(HSP_L0_30);
	
	cont1_btn9:Visible(true);
	cont1_btn9:SetText(HSP_L0_31);
	
	cont1_btn10:Visible(true);
	cont1_btn10:SetText(HSP_L0_32);
	
	cont1_btn11:Visible(true);
	cont1_btn11:SetText(HSP_L0_33);
	
	cont1_btn12:Visible(true);
	cont1_btn12:SetText(HSP_L0_34);
	
	container1:Auto();
	func_select_flags = 3;
end
--法师
function HelpSystem_OnClickPriestBtn()
	HelpSystem_Initcontainer1();
	
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_35);
	
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_36);
	
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_37);
	
	cont1_btn4:Visible(true);
	cont1_btn4:SetText(HSP_L0_38);
	
	cont1_btn5:Visible(true);
	cont1_btn5:SetText(HSP_L0_39);
	
	cont1_btn6:Visible(true);
	cont1_btn6:SetText(HSP_L0_40);
	
	cont1_btn7:Visible(true);
	cont1_btn7:SetText(HSP_L0_41);
	
	cont1_btn8:Visible(true);
	cont1_btn8:SetText(HSP_L0_42);
	
	cont1_btn9:Visible(true);
	cont1_btn9:SetText(HSP_L0_43);
	
	cont1_btn10:Visible(true);
	cont1_btn10:SetText(HSP_L0_44);
	
	cont1_btn11:Visible(true);
	cont1_btn11:SetText(HSP_L0_45);
	
	container1:Auto();
	func_select_flags = 4;
end

--1级按钮 第一个按钮的功能
function HelpSystem_OnClickBtn1()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(1);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(101)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(201)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(301)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 1;
end

--1级按钮 第二个按钮的功能
function HelpSystem_OnClickBtn2()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(2);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(102)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(202)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(302)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 2;
end

--1级按钮 第三个按钮的功能
function HelpSystem_OnClickBtn3()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(3);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(103)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(203)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(303)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 3;
end

--1级按钮 第四个按钮的功能
function HelpSystem_OnClickBtn4()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(4);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(104)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(204)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(304)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 4;
end

--1级按钮 第五个按钮的功能
function HelpSystem_OnClickBtn5()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(5);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(105)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(205)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(305)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 5;
end

--1级按钮 第六个按钮的功能
function HelpSystem_OnClickBtn6()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(6);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(106)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(206)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(306)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 6;
end

--1级按钮 第七个按钮的功能
function HelpSystem_OnClickBtn7()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(7);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(107)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(207)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(307)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 7;
end

--1级按钮 第八个按钮的功能
function HelpSystem_OnClickBtn8()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(8);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(108)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(208)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(308)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 8;
end

--1级按钮 第九个按钮的功能
function HelpSystem_OnClickBtn9()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(9);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(109)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(209)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(309)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 9;
end

--1级按钮 第十个按钮的功能
function HelpSystem_OnClickBtn10()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		HelpSystem_ReadSkillInfo(10);		
	elseif func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(110)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(210)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(310)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 10;
end

--1级按钮 第十一个按钮的功能
function HelpSystem_OnClickBtn11()
	HelpSystem_Initcontainer1();

	if func_select_flags == 2 then	
		HelpSystem_ReadSkillInfo(111)
	elseif func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(211)
	elseif func_select_flags == 4 then	
		HelpSystem_ReadSkillInfo(311)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 11;
end

--1级按钮 第十一个按钮的功能
function HelpSystem_OnClickBtn12()
	HelpSystem_Initcontainer1();

	if func_select_flags == 3 then	
		HelpSystem_ReadSkillInfo(212)
	end
	--返回上一页按钮
	HelpSystem_cont1FirstTextAuto();
	first_select_flags = 12;
end

--技能的
function HelpSystem_ReadSkillInfo(skillID)
	HelpSystem_Initcontainer1();
	--Base:Print("|cFFFF0000PlayerInfo_Loaded");
	
	t=Get_HelpSystem_SkillCofig(skillID);
	
	if t ~= nil then
		static_str3 = HSP_L0_46;
		static_str4 =HSP_L0_47;
		static_str5 =HSP_L0_48;
		if t.ID == nil then
			allstr=t.Descrip;
			cont1_text:SetText(allstr);	
			return;
		end
		
		if t.Descrip ~= nil then
			allstr=t.Descrip.."\n\n";
		else 
			allstr="";
		end
		
		if t.MaxLev == 3 then
			str = string.format("%18s%s","",static_str3);
			allstr = allstr..str.."\n";	
		elseif t.MaxLev == 4 then
			str = string.format("%18s%s","",static_str4);
			allstr = allstr..str.."\n";
		elseif t.MaxLev == 5 then		
			str = string.format("%18s%s","",static_str5);
			allstr = allstr..str.."\n";
		end
		
		size1 = string.len("大");
		print(size1);
		size2 = string.len("s");
		print(size2);
		size3 = string.len("：");
		print(size3);
		
		--读取基础伤害
		if t.Power2 ~= nil then
			p2_1 =GameAPI:GetSkillMagic(t.ID,"Power2");
			p2_2 =GameAPI:GetSkillMagic(t.ID+1,"Power2");
			p2_3 =GameAPI:GetSkillMagic(t.ID+2,"Power2");	
							
			size = string.len(t.Power2);							
			--str = string.format("%s%8s",t.Power2,"");
			if size == 15 then
				str = string.format("%s%9s",t.Power2,"");
			elseif size == 11 then 
				str = string.format("%s%7s",t.Power2,"");
			elseif size == 22 then 
				str = string.format("%s%4s",t.Power2,"");
			else
				str = string.format("%s%11s",t.Power2,"");			
			end
			allstr = allstr..str;	

			
			size = string.len(p2_1);
			if size == 4 then
				str = string.format("%s%4s",p2_1,"");
			elseif size == 3 then 
				str = string.format("%s%4s",p2_1,"");
			elseif size == 2 then 
				str = string.format("%s%6s",p2_1,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",p2_1,"");			
			end			
			allstr = allstr..str;	

			size = string.len(p2_2);
			if size == 4 then
				str = string.format("%s%4s",p2_2,"");
			elseif size == 3 then 
				str = string.format("%s%5s",p2_2,"");
			elseif size == 2 then 
				str = string.format("%s%6s",p2_2,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",p2_2,"");			
			end			
			allstr = allstr..str;	
			
			size = string.len(p2_3);
			if size == 4 then
				str = string.format("%s%3s",p2_3,"");
			elseif size == 3 then 
				str = string.format("%s%5s",p2_3,"");
			elseif size == 2 then 
				str = string.format("%s%6s",p2_3,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",p2_3,"");			
			end			
			allstr = allstr..str;	
			
			if t.MaxLev > 3 then
				p2_4 =GameAPI:GetSkillMagic(t.ID+3,"Power2");	
				size = string.len(p2_4);
				if size == 4 then
					str = string.format("%s%4s",p2_4,"");
				elseif size == 3 then 
					str = string.format("%s%7s",p2_4,"");
				elseif size == 2 then 
					str = string.format("%s%8s",p2_4,"");				
				elseif size == 1 then 
					str = string.format("%s%9s",p2_4,"");			
				end			
				allstr = allstr..str;	
			end
			
			if t.MaxLev > 4 then
				p2_5 =GameAPI:GetSkillMagic(t.ID+4,"Power2");		
				str = string.format("%s",p2_5,"");	
				allstr = allstr..str;	
			end

			allstr = allstr.."\n";		
		end
		
		--读取伤害加成
		if t.Power1 ~= nil then
			p1_1 =GameAPI:GetSkillMagic(t.ID,"Power1");
			p1_2 =GameAPI:GetSkillMagic(t.ID+1,"Power1");
			p1_3 =GameAPI:GetSkillMagic(t.ID+2,"Power1");	
							
			size = string.len(t.Power1);			
			if size == 15 then
				str = string.format("%s%9s",t.Power1,"");
			elseif size == 11 then 
				str = string.format("%s%7s",t.Power1,"");
			elseif size == 22 then 
				str = string.format("%s%2s",t.Power1,"");
			else
				str = string.format("%s%5s",t.Power1,"");			
			end
			allstr = allstr..str;	
			
			size = string.len(p1_1);
			if size == 4 then
				str = string.format("%s%s%3s",p1_1,"%","");
			elseif size == 3 then 
				str = string.format("%s%s%4s",p1_1,"%","");
		    elseif size ==2 then 
				str = string.format("%s%s%5s",p1_1,"%","");	
			elseif  size == 1 then
                str = string.format("%s%s%7s",p1_1,"%","")		
			end			
				allstr = allstr..str;	

			size = string.len(p1_2);
			if size == 4 then
				str = string.format("%s%s%3s",p1_2,"%","");
			elseif size == 3 then 
				str = string.format("%s%s%4s",p1_2,"%","");
			elseif size ==2 then 
				str = string.format("%s%s%5s",p1_2,"%","");	
			elseif  size == 1 then
                str = string.format("%s%s%7s",p1_2,"%","")			
			end			
				allstr = allstr..str;	
			
			size = string.len(p1_3);
			if size == 4 then
				str = string.format("%s%s%3s",p1_3,"%","");
			elseif size == 3 then 
				str = string.format("%s%s%4s",p1_3,"%","");
		    elseif size==2 then 
				str = string.format("%s%s%5s",p1_3,"%","");	
			elseif  size == 1 then
                str = string.format("%s%s%7s",p1_3,"%","")			
			end			
				allstr = allstr..str;	
			
			if t.MaxLev > 3 then
				p1_4 =GameAPI:GetSkillMagic(t.ID+3,"Power1");	
				size = string.len(p1_4);
				if size == 4 then
					str = string.format("%s%s%5s",p1_4,"%","");
				elseif size == 3 then 
					str = string.format("%s%s%4s",p1_4,"%","");
				elseif size == 2 then 
				str = string.format("%s%s%3s",p1_4,"%","");	
			    elseif  size == 1 then
                str = string.format("%s%s%2s",p1_4,"%","")				
				end			
					allstr = allstr..str;	
			end
			
			if t.MaxLev > 4 then
				p1_5 =GameAPI:GetSkillMagic(t.ID+4,"Power1");		
				str = string.format("%s%s",p1_5,"%");		
				allstr = allstr..str;	
			end

			allstr = allstr.."\n";		
		end		
		--有状态的
		sta_1 =GameAPI:GetSkillMagic(t.ID,"Status");			
		if sta_1 ~= -1 then
			sta_2 =GameAPI:GetSkillMagic(t.ID+1,"Status");
			sta_3 =GameAPI:GetSkillMagic(t.ID+2,"Status");
			--读取状态伤害				
			if t.Values ~= nil then
				val_1 =GameAPI:GetSkillStatus(sta_1,"Values");
				val_2 =GameAPI:GetSkillStatus(sta_2,"Values");
				val_3 =GameAPI:GetSkillStatus(sta_3,"Values");	
								
				size = string.len(t.Values);			
				if size == 15 then
					str = string.format("%s%5s",t.Values,"");
				elseif size == 11 then 
					str = string.format("%s%7s",t.Values,"");
				elseif size == 22 then 
					str = string.format("%s%2s",t.Values,"");
				else
					str = string.format("%s%5s",t.Values,"");			
				end
				allstr = allstr..str;
				
				size = string.len(val_1);
				if size == 4 then
					str = string.format("%s%4s",val_1,"");
				elseif size == 3 then 
					str = string.format("%s%5s",val_1,"");
				elseif size == 2 then 
					str = string.format("%s%6s",val_1,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",val_1,"");			
				end			
				allstr = allstr..str;	
	
				size = string.len(val_2);
				if size == 4 then
					str = string.format("%s%4s",val_2,"");
				elseif size == 3 then 
					str = string.format("%s%5s",val_2,"");
				elseif size == 2 then 
					str = string.format("%s%6s",val_2,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",val_2,"");			
				end			
				allstr = allstr..str;	
				
				size = string.len(val_3);
				if size == 4 then
					str = string.format("%s%4s",val_3,"");
				elseif size == 3 then 
					str = string.format("%s%5s",val_3,"");
				elseif size == 2 then 
					str = string.format("%s%6s",val_3,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",val_3,"");			
				end			
				allstr = allstr..str;	
				
				if t.MaxLev > 3 then
					sta_4 =GameAPI:GetSkillMagic(t.ID+3,"Status");
					val_4 =GameAPI:GetSkillStatus(sta_4,"Values");	
					size = string.len(val_4);
					if size == 4 then
						str = string.format("%s%6s",val_4,"");
					elseif size == 3 then 
						str = string.format("%s%7s",val_4,"");
					elseif size == 2 then 
						str = string.format("%s%8s",val_4,"");				
					elseif size == 1 then 
						str = string.format("%s%9s",val_4,"");			
					end			
					allstr = allstr..str;	
				end
				
				if t.MaxLev > 4 then
					sta_5 =GameAPI:GetSkillMagic(t.ID+4,"Status");				
					val_5 =GameAPI:GetSkillStatus(sta_5,"Values");	
					str = string.format("%s",val_5,"");	
					allstr = allstr..str;	
				end
	
				allstr = allstr.."\n";		
			end
		
			--读取状态持续时间
			if t.Time ~= nil then
				time_1 =GameAPI:GetSkillStatus(sta_1,"Time");
				time_2 =GameAPI:GetSkillStatus(sta_2,"Time");
				time_3 =GameAPI:GetSkillStatus(sta_3,"Time");	
								
				size = string.len(t.Time);			
				if size == 15 then
					str = string.format("%s%5s",t.Time,"");
				elseif size == 11 then 
					str = string.format("%s%7s",t.Time,"");
				elseif size == 22 then 
					str = string.format("%s%5s",t.Time,"");
				else
					str = string.format("%s%5s",t.Time,"");			
				end
				allstr = allstr..str;	
				
				size = string.len(time_1);
				if size == 4 then
					str = string.format("%s%4s",time_1,"");
				elseif size == 3 then 
					str = string.format("%s%5s",time_1,"");
				elseif size == 2 then 
					str = string.format("%s%6s",time_1,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",time_1,"");			
				end			
				allstr = allstr..str;	
	
				size = string.len(time_2);
				if size == 4 then
					str = string.format("%s%4s",time_2,"");
				elseif size == 3 then 
					str = string.format("%s%5s",time_2,"");
				elseif size == 2 then 
					str = string.format("%s%6s",time_2,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",time_2,"");			
				end			
				allstr = allstr..str;	
				
				size = string.len(time_3);
				if size == 4 then
					str = string.format("%s%4s",time_3,"");
				elseif size == 3 then 
					str = string.format("%s%5s",time_3,"");
				elseif size == 2 then 
					str = string.format("%s%6s",time_3,"");				
				elseif size == 1 then 
					str = string.format("%s%7s",time_3,"");			
				end			
				allstr = allstr..str;	
				
				if t.MaxLev > 3 then
					sta_4 =GameAPI:GetSkillMagic(t.ID+3,"Status");
					time_4 =GameAPI:GetSkillStatus(sta_4,"Time");	
					size = string.len(time_4);
					if size == 4 then
						str = string.format("%s%6s",time_4,"");
					elseif size == 3 then 
						str = string.format("%s%7s",time_4,"");
					elseif size == 2 then 
						str = string.format("%s%8s",time_4,"");				
					elseif size == 1 then 
						str = string.format("%s%7s",time_4,"");			
					end			
					allstr = allstr..str;	
				end
				
				if t.MaxLev > 4 then
					sta_5 =GameAPI:GetSkillMagic(t.ID+4,"Status");				
					time_5 =GameAPI:GetSkillStatus(sta_5,"Time");	
					str = string.format("%s",time_5,"");	
					allstr = allstr..str;	
				end
	
				allstr = allstr.."\n";		
			end
		end
		--读取冷却时间
		if t.CoolingTime ~= nil then
			cot_1 =GameAPI:GetSkillMagic(t.ID,"CoolingTime");
			cot_2 =GameAPI:GetSkillMagic(t.ID+1,"CoolingTime");
			cot_3 =GameAPI:GetSkillMagic(t.ID+2,"CoolingTime");	
							
			size = string.len(t.CoolingTime);			
			if size == 15 then
				str = string.format("%s%9s",t.CoolingTime,"");
			elseif size == 11 then 
				str = string.format("%s%7s",t.CoolingTime,"");
			elseif size == 22 then 
				str = string.format("%s%2s",t.CoolingTime,"");
			else
				str = string.format("%s%5s",t.CoolingTime,"");			
			end
			allstr = allstr..str;	
			
			size = string.len(cot_1);
			if size == 4 then
				str = string.format("%s%4s",cot_1,"");
			elseif size == 3 then 
				str = string.format("%s%5s",cot_1,"");
			elseif size == 2 then 
				str = string.format("%s%6s",cot_1,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",cot_1,"");			
			end				
			allstr = allstr..str;	

			size = string.len(cot_2);
			if size == 4 then
				str = string.format("%s%4s",cot_2,"");
			elseif size == 3 then 
				str = string.format("%s%5s",cot_2,"");
			elseif size == 2 then 
				str = string.format("%s%6s",cot_2,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",cot_2,"");			
			end			
			allstr = allstr..str;	
			
			size = string.len(cot_3);
			if size == 4 then
				str = string.format("%s%4s",cot_3,"");
			elseif size == 3 then 
				str = string.format("%s%5s",cot_3,"");
			elseif size == 2 then 
				str = string.format("%s%6s",cot_3,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",cot_3,"");			
			end			
			allstr = allstr..str;	
			
			if t.MaxLev > 3 then
				cot_4 =GameAPI:GetSkillMagic(t.ID+3,"CoolingTime");	
				size = string.len(cot_4);
				if size == 4 then
					str = string.format("%s%6s",cot_4,"");
				elseif size == 3 then 
					str = string.format("%s%7s",cot_4,"");
				elseif size == 2 then 
					str = string.format("%s%6s",cot_4,"");				
				elseif size == 1 then 
					str = string.format("%s%9s",cot_4,"");			
				end			
				allstr = allstr..str;	
			end
			
			if t.MaxLev > 4 then
				cot_5 =GameAPI:GetSkillMagic(t.ID+4,"CoolingTime");		
				str = string.format("%s",cot_5);
				allstr = allstr..str;	
			end

			allstr = allstr.."\n";		
		end		
		--读取消耗MP
		if t.MP ~= nil then
			mp_1 =GameAPI:GetSkillMagic(t.ID,"MP");
			mp_2 =GameAPI:GetSkillMagic(t.ID+1,"MP");
			mp_3 =GameAPI:GetSkillMagic(t.ID+2,"MP");	
							
			size = string.len(t.MP);			
			if size == 15 then
				str = string.format("%s%5s",t.MP,"");
			elseif size == 11 then 
				str = string.format("%s%11s",t.MP,"");
			elseif size == 22 then 
				str = string.format("%s%2s",t.MP,"");
			else
				str = string.format("%s%5s",t.MP,"");			
			end
			allstr = allstr..str;	
			
			size = string.len(mp_1);
			if size == 4 then
				str = string.format("%s%4s",mp_1,"");
			elseif size == 3 then 
				str = string.format("%s%5s",mp_1,"");
			elseif size == 2 then 
				str = string.format("%s%6s",mp_1,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",mp_1,"");			
			end				
			allstr = allstr..str;	

			size = string.len(mp_2);
			if size == 4 then
				str = string.format("%s%4s",mp_2,"");
			elseif size == 3 then 
				str = string.format("%s%5s",mp_2,"");
			elseif size == 2 then 
				str = string.format("%s%6s",mp_2,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",mp_2,"");			
			end			
			allstr = allstr..str;	
			
			size = string.len(mp_3);
			if size == 4 then
				str = string.format("%s%4s",mp_3,"");
			elseif size == 3 then 
				str = string.format("%s%4s",mp_3,"");
			elseif size == 2 then 
				str = string.format("%s%6s",mp_3,"");				
			elseif size == 1 then 
				str = string.format("%s%7s",mp_3,"");			
			end			
			allstr = allstr..str;	
			
			if t.MaxLev > 3 then
				mp_4 =GameAPI:GetSkillMagic(t.ID+3,"MP");	
				size = string.len(mp_4);
				if size == 4 then
					str = string.format("%s%4s",mp_4,"");
				elseif size == 3 then 
					str = string.format("%s%5s",mp_4,"");
				elseif size == 2 then 
					str = string.format("%s%4s",mp_4,"");				
				elseif size == 1 then 
					str = string.format("%s%4s",mp_4,"");			
				end			
				allstr = allstr..str;	
			end
			
			if t.MaxLev > 4 then
				mp_5 =GameAPI:GetSkillMagic(t.ID+4,"MP");		
				str = string.format("%s",mp_5);		
				allstr = allstr..str;	
			end

			allstr = allstr.."\n";		
		end
		
		allstr = allstr..t.Level.."\n";		
		
		cont1_text:SetText(allstr);		

	end

	cont1_text:Auto();
	container1:Auto();	
end
--任务功能
function HelpSystem_taviaOnClickQuestBtn()
	HelpSystem_Initcontainer1();
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_49);
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_50);
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_51);
	container1:Auto();
	func_select_flags = 1;
end
--技能功能
function HelpSystem_taviaOnClickSkillBtn()
	HelpSystem_Initcontainer1();
	cont1_btn1:Visible(true);
	cont1_btn1:SetText(HSP_L0_52);
	cont1_btn2:Visible(true);	
	cont1_btn2:SetText(HSP_L0_53);
	cont1_btn3:Visible(true);
	cont1_btn3:SetText(HSP_L0_54);
	container1:Auto();
	func_select_flags = 2;
end
--1级按钮 第一个按钮的功能
function HelpSystem_taviaOnClickBtn1()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText(HSP_L0_55);
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_56);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_57);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	elseif func_select_flags == 2 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText(HSP_L0_58);
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_59);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_60);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	end
end

--1级按钮 第一个按钮的功能
function HelpSystem_taviaOnClickBtn1()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText("HSP_L0_55");
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_56);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_57);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	elseif func_select_flags == 2 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText(HSP_L0_58);
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_59);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_60);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	end
	first_select_flags = 1;

end

--1级按钮 第二个按钮的功能
function HelpSystem_taviaOnClickBtn2()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText(HSP_L0_61);
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_62);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_63);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	elseif func_select_flags == 2 then
		cont1_btn101:Visible(true);
		cont1_btn101:SetText(HSP_L0_64);
		cont1_btn102:Visible(true);	
		cont1_btn102:SetText(HSP_L0_65);
		cont1_btn103:Visible(true);
		cont1_btn103:SetText(HSP_L0_66);
		--返回上一页按钮
		HelpSystem_cont1FirstAuto(cont1_btn103)
	end
	first_select_flags = 2;

end

--2级按钮 第一个按钮的功能
function HelpSystem_taviaOnClickBtn101()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		if first_select_flags == 1 then
			cont1_text:SetText(Get_HelpSystem_Cofig(2).static_text);			
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		elseif first_select_flags == 2 then	
			cont1_text:SetText(HSP_L0_67);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		end 
	elseif func_select_flags == 2 then	
		if first_select_flags == 1 then
			cont1_text:SetText(Get_HelpSystem_Cofig(3).static_text);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		elseif first_select_flags == 2 then	
			cont1_text:SetText(HSP_L0_68);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		end 
	end
	second_select_flags = 1;
end

--2级按钮 第二个按钮的功能
function HelpSystem_taviaOnClickBtn102()
	HelpSystem_Initcontainer1();
	if func_select_flags == 1 then
		if first_select_flags == 1 then
			cont1_text:SetText(HSP_L0_69);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		elseif first_select_flags == 2 then	
			cont1_text:SetText(HSP_L0_70);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		end 
	elseif func_select_flags == 2 then	
		if first_select_flags == 1 then
			cont1_text:SetText(HSP_L0_71);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		elseif first_select_flags == 2 then	
			cont1_text:SetText(HSP_L0_72);
			--返回上一页按钮
			HelpSystem_cont1SecondAuto();
		end 
	end
	second_select_flags = 2;
end

--1级返回上一页按钮的功能
function HelpSystem_BackFirstBtn()
	if func_select_flags == 1 then
		HelpSystem_OnClickWarriorBtn();
	elseif func_select_flags == 2 then	
		HelpSystem_OnClickChampionBtn();
	elseif func_select_flags == 3 then	
		HelpSystem_OnClickMgaeBtn();
	elseif func_select_flags == 4 then	
		HelpSystem_OnClickPriestBtn();
	end 

end
--2级返回上一页按钮的功能
function HelpSystem_BackSecondBtn()
	if first_select_flags == 1 then
		HelpSystem_OnClickBtn1();
	elseif first_select_flags == 2 then	
		HelpSystem_OnClickBtn2();
	end				
end
--返回上一级按钮的功能
function HelpSystem_BackFrontBtn()
	if func_select_flags == 1 then
		HelpSystem_OnClickQuestBtn();
	elseif func_select_flags == 2 then	
		HelpSystem_OnClickSkillBtn();
	end 		
end
--初始化容器2的内容
function HelpSystem_Initcontainer1()
	cont1_text:SetText("");	
	cont1_btn1:Visible(false);
	cont1_btn2:Visible(false);
	cont1_btn3:Visible(false);

	cont1_btn4:Visible(false);
	cont1_btn5:Visible(false);
	cont1_btn6:Visible(false);
	cont1_btn7:Visible(false);
	cont1_btn8:Visible(false);
	cont1_btn9:Visible(false);
	cont1_btn10:Visible(false);
	cont1_btn11:Visible(false);
	cont1_btn12:Visible(false);
	
	cont1_btn101:Visible(false);
	cont1_btn102:Visible(false);
	cont1_btn103:Visible(false);
	cont1_backfirstbtn:Visible(false);
	cont1_backsecondbtn:Visible(false);
	cont1_backfrontbtn:Visible(false);
	cont1_temptext:Visible(false);
	uiapi:SetScrollPos(0,container1:GetChild(0));
	container1:Auto();	
end
--调整1级返回上一页按钮的位置
function HelpSystem_cont1FirstAuto(btn)
	--返回上一页按钮					
	cont1_text:Auto();
	x , y = btn:GetPosition();
	y = y+50;
	h = btn:GetHeight();	
	cont1_temptext:Auto();
	cont1_backfirstbtn:SetPosition(x , y+h+50);	
	cont1_backfirstbtn:Visible(true);
	container1:Auto();		
end
--调整1级纯文本返回上一页按钮的位置
function HelpSystem_cont1FirstTextAuto()
	--返回上一页按钮					
	cont1_text:Auto();
	x , y = cont1_text:GetPosition();
	y = y+50;
	h = cont1_text:GetHeight();	
	cont1_temptext:Auto();
	cont1_backfirstbtn:SetPosition(x , y+h+50);	
	cont1_backfirstbtn:Visible(true);
	container1:Auto();		
end

--调整2级返回上一页按钮的位置
function HelpSystem_cont1SecondAuto()
	--返回上一页按钮					
	cont1_text:Auto();
	x , y = cont1_text:GetPosition();
	h = cont1_text:GetHeight();					
	cont1_backsecondbtn:SetPosition(x , y+h+50);
	cont1_backfrontbtn:SetPosition(x , y+h+80);	
	cont1_backsecondbtn:Visible(true);
	cont1_backfrontbtn:Visible(true);
	container1:Auto();		
end
--mian之前初始化xml返回上一页自己加载。
	HelpSystem_OnLoad();

function HlepSystem_OnTextSelect()

	print(UIAPI:GetTextSelect(cont1_text));

end




