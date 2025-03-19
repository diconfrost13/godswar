print("success");

--定义拓展的NPC功能类型
--NPC_FLAG_SYS
local NPC_FLAG_SYS_NONE    = 0
local NPC_FLAG_SYS_TRANMIT = 1  --传送
local NPC_FLAG_SYS_CREDIT_EXCHANGE = 2 --声望
local NPC_FLAG_SYS_GRANT_OFFICAL   = 4 --官职
local NPC_FLAG_SYS_OFFICAL_SALARY  = 8  --俸禄
local NPC_FLAG_SYS_ALTAR = 16  --祭坛
local NPC_FLAG_GUILDQUEST = 32  --公会任务

--获取所有UI资源
local win = UIAPI:GetElement("FirstWin");
local FirstWin_Text1= win:GetChild("FirstWin_Text1");
local FirstWin_Text2= win:GetChild("FirstWin_Text2");
local FirstWin_Text3= win:GetChild("FirstWin_Text3");
		
local FirstWin_Button1 = win:GetChild("FirstWin_Button1");
local FirstWin_Button2 = win:GetChild("FirstWin_Button2");
local FirstWin_Button3 = win:GetChild("FirstWin_Button3");
local FirstWin_Button4 = win:GetChild("FirstWin_Button4");
local FirstWin_Button5 = win:GetChild("FirstWin_Button5");
local FirstWin_Button6 = win:GetChild("FirstWin_Button6");
local FirstWin_Button7 = win:GetChild("FirstWin_Button7");
local FirstWin_Button8 = win:GetChild("FirstWin_Button8");
local FirstWin_Button9 = win:GetChild("FirstWin_Button9");
local FirstWin_Button10 = win:GetChild("FirstWin_Button10");
        
local FirstWin_CheckBox1 = win:GetChild("FirstWin_CheckBox1");
local FirstWin_CheckBox2 = win:GetChild("FirstWin_CheckBox2");
local FirstWin_CheckBox3 = win:GetChild("FirstWin_CheckBox3");
local FirstWin_CheckBox4 = win:GetChild("FirstWin_CheckBox4");
		
local FirstWin_ButtonA1 = win:GetChild("FirstWin_ButtonA1");
local FirstWin_ButtonA2 = win:GetChild("FirstWin_ButtonA2");

--显示不同类型的窗体界面
function Set_NpcFun_UI(Type,Index)
        print("Set_NpcFun_UI()");
        print(Type);
	SetOriginalPosition();

	FirstWin_Text1:Visible(false);
	FirstWin_Text2:Visible(false);
	FirstWin_Text3:Visible(false);

	FirstWin_Button1:Visible(false);
	FirstWin_Button2:Visible(false);
	FirstWin_Button3:Visible(false);
	FirstWin_Button4:Visible(false);
	FirstWin_Button5:Visible(false);
	FirstWin_Button6:Visible(false);
	FirstWin_Button7:Visible(false);
	FirstWin_Button8:Visible(false);
	FirstWin_Button9:Visible(false);
	FirstWin_Button10:Visible(false);

	FirstWin_CheckBox1:Visible(false);
	FirstWin_CheckBox2:Visible(false);
	FirstWin_CheckBox3:Visible(false);
	FirstWin_CheckBox4:Visible(false);

	FirstWin_ButtonA1:Visible(false);
	FirstWin_ButtonA2:Visible(false);

    	if Type == NPC_FLAG_SYS_TRANMIT  then
		FirstWin_ButtonA1:Visible(true);
		FirstWin_ButtonA2:Visible(true);
		win:Visible(true);
        elseif Type == NPC_FLAG_SYS_CREDIT_EXCHANGE  then
		FirstWin_ButtonA1:Visible(true);
		FirstWin_ButtonA2:Visible(true);
		win:Visible(true);
    	elseif Type == NPC_FLAG_SYS_GRANT_OFFICAL  then
		FirstWin_ButtonA1:Visible(true);
		FirstWin_ButtonA2:Visible(true);
		win:Visible(true);
    	elseif Type == NPC_FLAG_SYS_OFFICAL_SALARY then
		FirstWin_ButtonA1:Visible(true);
		FirstWin_ButtonA2:Visible(true);
		win:Visible(true);
    	elseif Type == NPC_FLAG_SYS_ALTAR then
                if Index == 1 then
	           FirstWin_Text1:SetPosition(45,100);
	           FirstWin_Text2:SetPosition(45,120);
	           FirstWin_Text3:SetPosition(45,140);

        	   FirstWin_Button1:SetPosition(45,160);
               	   FirstWin_Button2:SetPosition(45,185);
         	   FirstWin_Button3:SetPosition(45,210);
	           FirstWin_Button4:SetPosition(45,235);
	           FirstWin_Button5:SetPosition(45,260);
	           FirstWin_Button6:SetPosition(45,285);
	           FirstWin_Button7:SetPosition(45,310);
	           FirstWin_Button8:SetPosition(45,335);
	           FirstWin_Button9:SetPosition(45,360);
	           FirstWin_Button10:SetPosition(45,385);

	           FirstWin_ButtonA1:SetPosition(145,500);
	           FirstWin_ButtonA2:SetPosition(220,500);
		   FirstWin_ButtonA1:Visible(true);
		   FirstWin_ButtonA2:Visible(true);
		   win:Visible(true);
                end;
                if Index == 2 then
	           FirstWin_Text1:SetPosition(45,100);
	           FirstWin_Text2:SetPosition(45,120);
	           FirstWin_Text3:SetPosition(45,140);

        	   FirstWin_Button1:SetPosition(40,160);
               	   FirstWin_Button2:SetPosition(40,185);
         	   FirstWin_Button3:SetPosition(40,210);
	           FirstWin_Button4:SetPosition(40,235);
	           FirstWin_Button5:SetPosition(40,260);
	           FirstWin_Button6:SetPosition(40,285);
	           FirstWin_Button7:SetPosition(40,310);
	           FirstWin_Button8:SetPosition(40,335);
	           FirstWin_Button9:SetPosition(40,360);
	           FirstWin_Button10:SetPosition(40,385);

	           FirstWin_ButtonA1:SetPosition(220,500);
	           FirstWin_ButtonA2:SetPosition(220,500);
		   FirstWin_ButtonA1:Visible(true);
		   FirstWin_ButtonA2:Visible(false);
		   win:Visible(true);
                end;
                if Index == 3 then
	           FirstWin_Text1:SetPosition(45,100);
	           FirstWin_Text2:SetPosition(45,120);
	           FirstWin_Text3:SetPosition(45,140);

        	   FirstWin_Button1:SetPosition(25,160);
               	   FirstWin_Button2:SetPosition(25,185);
         	   FirstWin_Button3:SetPosition(25,210);
	           FirstWin_Button4:SetPosition(25,235);
	           FirstWin_Button5:SetPosition(25,260);
	           FirstWin_Button6:SetPosition(25,285);
	           FirstWin_Button7:SetPosition(25,310);
	           FirstWin_Button8:SetPosition(25,335);
	           FirstWin_Button9:SetPosition(25,360);
	           FirstWin_Button10:SetPosition(25,385);

	           FirstWin_ButtonA1:SetPosition(220,500);
	           FirstWin_ButtonA2:SetPosition(220,500);
		   FirstWin_ButtonA1:Visible(true);
		   FirstWin_ButtonA2:Visible(false);
		   win:Visible(true);
                end;
    	elseif Type == NPC_FLAG_GUILDQUEST then
		FirstWin_ButtonA1:Visible(true);
		FirstWin_ButtonA2:Visible(true);
		win:Visible(true);
    	end;
end

--配置UI窗体信息生成自己想要的界面
function Set_NpcFun_Text(Type,Index,BtnID,SubID)
	if Type == NPC_FLAG_SYS_TRANMIT then    --------传送----------------------------------------------------------------------------------
		if Index == 1 then
			if SubID== 1 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到斯巴达郊外");
				Button:Visible(true);
			elseif SubID == 2 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到尼米亚");
				Button:Visible(true);
			elseif SubID == 3 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到伯罗奔尼撒");
				Button:Visible(true);
			elseif SubID == 4 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到雅典近郊");
				Button:Visible(true);
                	elseif SubID == 5 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到帕尼撒");
				Button:Visible(true);
                	elseif SubID == 6 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到马拉松");
				Button:Visible(true);
                	elseif SubID == 101 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到神迹雕像");
				Button:Visible(true);
                	elseif SubID == 102 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到神迹雕像");
				Button:Visible(true);
                	elseif SubID == 103 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("40级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 104 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("40级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 105 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("60级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 106 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("80级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 107 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("80级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 108 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("90级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 109 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("110级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 10 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("40级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 11 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("40级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 12 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("50级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 13 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("50级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 14 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("60级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 15 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("60级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 16 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("70级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 17 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("70级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 18 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("80级以上怪物区1");
				Button:Visible(true);
                	elseif SubID == 19 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("80级以上怪物区2");
				Button:Visible(true);
                	elseif SubID == 20 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("90级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 21 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("100级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 22 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("110级以上怪物区");
				Button:Visible(true);
                	elseif SubID == 201 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到诅咒之地");
				Button:Visible(true);
                	elseif SubID == 202 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到商旅宝库");
				Button:Visible(true);
                	elseif SubID == 300 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到曼提尼亚");
				Button:Visible(true);
                	elseif SubID == 301 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("传送到曼提尼亚");
				Button:Visible(true);
			end;
		elseif Index == 2 then
			if SubID == 1000 then
				FirstWin_Text1:SetText("马拉松的传送等级是30级,帕尼撒的传送等级是45级,你的等级不够不能传送.");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);
			elseif SubID == 1001 then
				FirstWin_Text1:SetText("伯罗奔尼撒的传送等级是30级,尼米亚的传送等级是45级,你的等级不够不能传送.");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);
			elseif SubID == 2001 then
				FirstWin_Text1:SetText("等级不符合要求不能传送.");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);
			elseif SubID == 1009 then
				FirstWin_Text1:SetText("诅咒之地的传送时间为9月29号-10月5号14:30-15:30,传送等级为40级,您的条件不符合.");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);
			elseif SubID == 1010 then
				FirstWin_Text1:SetText("商旅宝库的传送时间为9月29号-10月5号20:30-21:30,传送等级为40级,您的条件不符合.");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);
			elseif SubID == 1200 then
				FirstWin_Text1:SetText("曼提尼亚的传送时间为9月29号-10月5号22:30-23:00,传送等级为35级以上,传送间隔为5分钟一个周期,前三分钟传送,后两分钟关闭,您的条件不符合");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
                                NPCFUN:NeedMessage(False);


			end;
        	end;
	elseif Type == NPC_FLAG_SYS_CREDIT_EXCHANGE then    --------兑换-----------------------------------------------------------------------
		if Index == 1 then
			if SubID== 1 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("100声望兑换10000金钱");
				Button:Visible(true);
			elseif SubID == 2 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("100声望兑换25000经验");
				Button:Visible(true);
			elseif SubID == 3 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("60声望兑换蓝宝石碎片");
				Button:Visible(true);
			elseif SubID == 4 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("60声望兑换绿宝石碎片");
				Button:Visible(true);
			elseif SubID == 5 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("120声望兑换红宝石碎片");
				Button:Visible(true);
			end;
		elseif Index == 2 then --服务器消息提示
			if SubID == 1000 then
				FirstWin_Text1:SetText("恭喜你，你已经成功兑换！");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1001 then
				FirstWin_Text1:SetText("没有足够的声望，无法兑换……");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1002 then
				FirstWin_Text1:SetText("你的包裹已满，无法获得新道具，请整理……");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1003 then
				FirstWin_Text1:SetText("200级时无法兑换经验……");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			end;
        	end;
	elseif Type == NPC_FLAG_SYS_GRANT_OFFICAL then    --------国家官职----------------------------------------------------------------------
		if Index == 1 then
			if SubID== 1 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("按照你的声望,你可以升级为 一级官员");
				FirstWin_Text1:Visible(true);
			elseif SubID== 2 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("按照你的声望,你可以升级为 二级官员");
				FirstWin_Text1:Visible(true);
			elseif SubID== 3 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("按照你的声望,你可以升级为 三级官员");
				FirstWin_Text1:Visible(true);
			elseif SubID== 4 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("按照你的声望,你可以升级为 四级官员");
				FirstWin_Text1:Visible(true);
			elseif SubID== 5 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("按照你的声望,你可以升级为 五级官员");
				FirstWin_Text1:Visible(true);
			elseif SubID== 255 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你没有足够的声望升级官员");
				FirstWin_Text1:Visible(true);
			end;
		elseif Index == 2 then --服务器消息提示
			if SubID == 1000 then
				FirstWin_Text1:SetText("没有足够的金钱 不能兑换");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1001 then
				FirstWin_Text1:SetText("没有足够的金钱 不能兑换");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			end;
        	end;
	elseif Type == NPC_FLAG_SYS_OFFICAL_SALARY then  -------------------领取俸禄--------------------------------------------------------------
		if Index == 1 then
			if SubID== 1 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你可以领取的俸禄\n经验    100\n声望    1\n道具物品:");
				FirstWin_Text1:Visible(true);
			
				FirstWin_CheckBox1:GetChild(0):SetTexturePos(36,0);
				FirstWin_CheckBox1:Visible(true);

				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
			elseif SubID== 2 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你可以领取的俸禄\n经验    1000\n声望    10\n道具物品:");
				FirstWin_Text1:Visible(true);
			
				FirstWin_CheckBox1:GetChild(0):SetTexturePos(36,0);
				FirstWin_CheckBox1:Visible(true);

				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
			elseif SubID== 3 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你可以领取的俸禄\n经验    10000\n声望    100\n道具物品:");
				FirstWin_Text1:Visible(true);
			
				FirstWin_CheckBox1:GetChild(0):SetTexturePos(36,0);
				FirstWin_CheckBox1:Visible(true);

				FirstWin_CheckBox2:GetChild(0):SetTexturePos(72,0);
				FirstWin_CheckBox2:Visible(true);

				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
			elseif SubID== 4 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你可以领取的俸禄\n经验    100000\n声望    1000\n道具物品:");
				FirstWin_Text1:Visible(true);
			
				FirstWin_CheckBox1:GetChild(0):SetTexturePos(36,0);
				FirstWin_CheckBox1:Visible(true);

				FirstWin_CheckBox2:GetChild(0):SetTexturePos(72,0);
				FirstWin_CheckBox2:Visible(true);

				FirstWin_CheckBox3:GetChild(0):SetTexturePos(108,0);
				FirstWin_CheckBox3:Visible(true);

				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
			elseif SubID== 5 then
				print(BtnID,SubID);
				FirstWin_Text1:SetText("你可以领取的俸禄\n经验    1000000\n声望    10000\n道具物品:");
				FirstWin_Text1:Visible(true);
			
				FirstWin_CheckBox1:GetChild(0):SetTexturePos(36,0);
				FirstWin_CheckBox1:Visible(true);

				FirstWin_CheckBox2:GetChild(0):SetTexturePos(72,0);
				FirstWin_CheckBox2:Visible(true);

				FirstWin_CheckBox3:GetChild(0):SetTexturePos(108,0);
				FirstWin_CheckBox3:Visible(true);

				FirstWin_CheckBox4:GetChild(0):SetTexturePos(144,0);
				FirstWin_CheckBox4:Visible(true);

				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
				NPCFUN:SetItemData({Base=4000,BaseLv=1,AppendLv=1,Overlap=1,Binding=0,Append1=-1,Append2=-1,Append3=-1,Append4=-1,Append5=-1});
			end;
		elseif Index == 2 then --服务器消息提示
			if SubID == 1000 then
				FirstWin_Text1:SetText("俸禄");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1001 then
				FirstWin_Text1:SetText("俸禄");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			end;
        	end;
	elseif Type == NPC_FLAG_SYS_ALTAR then    --------------祭坛-----------------------------------------------------------------------------
		if Index== 1 then    ----第几个页面------
		        FirstWin_Text1:SetText("你好！我是公会祭司，可以为你提供以下服务，请选择：");
			FirstWin_Text1:Visible(true);
			if SubID== 1 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("创建祭坛");
				Button:Visible(true);
			elseif SubID== 2 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("删除祭坛");
				Button:Visible(true);
			elseif SubID==  3 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("升级祭坛");
				Button:Visible(true);
                        elseif SubID==  4 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("供奉神明");
				Button:Visible(true);
                        elseif SubID==  5 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("取消供奉");
				Button:Visible(true);
                        elseif SubID==  6 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("升级供奉");
				Button:Visible(true);
                        elseif SubID== 1000 then
                                FirstWin_Text1:SetText("对不起！你还未加入任何公会，请加入或者创建新的公会以后再来。");
                                FirstWin_Text1:Visible(true);
                                NPCFUN:EndMessage(true);
			end;

		elseif Index== 2 then
		        FirstWin_Text1:SetText("恩，请选择你所需要操作神明的祭坛：");
			FirstWin_Text1:Visible(true);
                        if SubID== 1001 then
                                FirstWin_Text1:SetText("已经达到公会能添加的祭坛的最大上限，请升级公会后再来。");
                                FirstWin_Text1:Visible(true);
                                NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID== 1002 then
                                FirstWin_Text1:SetText("公会目前还没有创建祭坛，请先创建祭坛后再来。");
                                FirstWin_Text1:Visible(true);
                                NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID== 1003 then
                                FirstWin_Text1:SetText("你已经供奉了公会现有的所有神明，你太伟大了。");
                                FirstWin_Text1:Visible(true);
                                NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID== 1004 then
                                FirstWin_Text1:SetText("你还没有供奉神明，请先供奉了神明再来。");
                                FirstWin_Text1:Visible(true);
                                NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
			end;
			if SubID== 1 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("阿波罗");
				Button:Visible(true);
			elseif SubID== 2 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("德墨忒耳");
				Button:Visible(true);
			elseif SubID==  3 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("赫耳墨斯");
				Button:Visible(true);
			elseif SubID== 4 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("赫淮斯托斯");
				Button:Visible(true);
			elseif SubID== 5 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("哈迪斯");
				Button:Visible(true);
			elseif SubID== 6 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("狄俄尼索斯");
				Button:Visible(true);
			elseif SubID== 7 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("阿芙洛狄忒");
				Button:Visible(true);
			elseif SubID== 8 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("赫斯提亚");
				Button:Visible(true);
			elseif SubID== 9 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("波塞冬");
				Button:Visible(true);
			elseif SubID== 10 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
				Button:SetText("阿尔忒弥斯");
				Button:Visible(true);
			end;		
		elseif Index == 3 then		--服务器提示消息
			if SubID == 1005 then
				FirstWin_Text1:SetText("很遗憾！你选择的操作错误或者无效。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
			elseif SubID == 1006 then
				FirstWin_Text1:SetText("太好了，你需要的祭坛已经添加成功。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1007 then
				FirstWin_Text1:SetText("很遗憾，你不满足祭坛添加的条件，所以添加失败了。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1008 then
				FirstWin_Text1:SetText("太好了，你需要的祭坛已经成功升级。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1009 then
				FirstWin_Text1:SetText("很遗憾，你不满足祭坛升级的条件，所以升级失败了。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1010 then
				FirstWin_Text1:SetText("你需要的祭坛已经成功删除。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1011 then
				FirstWin_Text1:SetText("很遗憾，你不满足祭坛删除的条件，所以删除失败了。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1012 then
				FirstWin_Text1:SetText("恭喜你，你成功供奉了新神明，神将赐予你新的力量。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1013 then
				FirstWin_Text1:SetText("很遗憾，你不满足供奉新神明的条件，所以神没有给予你回应。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1014 then
				FirstWin_Text1:SetText("你成功的解除了对神明的供奉，神收回了对你的庇护。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1015 then
				FirstWin_Text1:SetText("很遗憾，你不满足解除对神明供奉的条件，所以神没有给予你回应。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1016 then
				FirstWin_Text1:SetText("恭喜你，你对神明供奉的等级提升了，神将赐予你更强的力量。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
                        elseif SubID == 1017 then
				FirstWin_Text1:SetText("很遗憾，你不满足神明供奉等级提升的条件，所以神没有给予你回应。");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
				NPCFUN:NeedMessage(false);
			end;
		end;		
	elseif Type == NPC_FLAG_GUILDQUEST then	--------公会任务-----------------------------------------------------------------------

		if Index== 1 then    ----第几个页面------
			FirstWin_Text1:SetText("请选择发布给公会成员任务的种类：");
			FirstWin_Text1:Visible(true);
			if SubID== 1 or SubID == 3 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
                        	Button:SetPosition(25,150);
				Button:SetText("全员送信");
				Button:Visible(true);
			elseif SubID == 2 or SubID == 4 then
				print(BtnID,SubID);
				local Button = win:GetChild("FirstWin_Button" .. BtnID);
                        	Button:SetPosition(25,180);
				Button:SetText("全员杀怪");
				Button:Visible(true);
			end;
		elseif Index == 2 then	--服务器提示消息---------------------
			if SubID == 1000 then
				FirstWin_Text1:SetText("公会任务已发布");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			elseif SubID == 1001 then
				FirstWin_Text1:SetText("你不是会长或副会长，无法发布公会任务");
				FirstWin_Text1:Visible(true);
				NPCFUN:EndMessage(true);
			end;
		end;	
				
	end;
end



--客户端消息提示框--------------------------------------------------------------------------------------------
function Set_MessageBox(Type,Index,PreSubID,SubID)
	Set_NpcFun_UI(Type,Index);
	if Type == NPC_FLAG_SYS_TRANMIT2 then    --------传送提示框----------------------------------------------------------------------------------
		if SubID== 0 then
		elseif SubID== 10 then
			FirstWin_Text1:SetText("传送到斯巴达郊外 需要消耗100银币");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
		elseif SubID == 200 then
			FirstWin_Text1:SetText("马拉松的传送等级是30级,帕尼撒的传送等级是45级,你的等级不够不能传送");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
		elseif SubID == 30 then
			FirstWin_Text1:SetText("传送到斯巴达 需要消耗100银币");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
		elseif SubID == 40 then
			FirstWin_Text1:SetText("传送到雅典近郊 需要消耗100银币");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
                elseif SubID == 500 then
			FirstWin_Text1:SetText("我只能帮45级以上的人传送到帕尼撒");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
                elseif SubID == 60 then
			FirstWin_Text1:SetText("传送到雅典近郊 需要消耗100银币");
			FirstWin_Text1:Visible(true);
			NPCFUN:HaveMessageBox(true);
		end;
	elseif Type == NPC_FLAG_SYS_CREDIT_EXCHANGE then    --------兑换提示框-----------------------------------------------------------------------
		if SubID== 0 then
		elseif SubID== 1 then
		elseif SubID == 2 then
		elseif SubID == 3 then
		elseif SubID == 4 then
		elseif SubID == 5 then
		end;
	elseif Type == NPC_FLAG_SYS_GRANT_OFFICAL then    --------国家官职提示框----------------------------------------------------------------------
		if SubID== 0 then
		elseif SubID== 1 then
		elseif SubID== 2 then
		elseif SubID== 3 then
		elseif SubID== 4 then
		elseif SubID== 5 then
		elseif SubID== 255 then
		end;
	elseif Type == NPC_FLAG_SYS_OFFICAL_SALARY then  -------------------领取俸禄提示框--------------------------------------------------------------
		if SubID== 1 then
		elseif SubID== 2 then
		elseif SubID== 3 then
		elseif SubID== 4 then
		elseif SubID== 5 then
		end;
	elseif Type == NPC_FLAG_SYS_ALTAR then    --------------祭坛-----------------------------------------------------------------------------
		if Index== 2 then
                    FirstWin_ButtonA1:SetPosition(145,500);
	            FirstWin_ButtonA2:SetPosition(220,500);
		    FirstWin_ButtonA1:Visible(true);
		    FirstWin_ButtonA2:Visible(true); 	  	
			if PreSubID == 1 then  --创建祭坛
                            if SubID== 1 then
				FirstWin_Text1:SetText("供奉阿波罗能够提升供奉者HP和MP的最大上限。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 2 then
				FirstWin_Text1:SetText("供奉德墨忒耳能够提升供奉者的HP回复能力和伤害吸收能力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 3 then
				FirstWin_Text1:SetText("供奉赫耳墨斯能够提升供奉者的MP回复能力和MP最大上限。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 4 then
				FirstWin_Text1:SetText("供奉赫淮斯托斯能够提升供奉者的物理攻击力和命中。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 5 then
				FirstWin_Text1:SetText("供奉哈迪斯能够提升供奉者的魔法攻击力和物理攻击力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 6 then
				FirstWin_Text1:SetText("供奉狄俄尼索斯能够提升供奉者的物理防御力和魔法防御力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 7 then
				FirstWin_Text1:SetText("供奉阿芙洛狄忒能够提升供奉者的魔法防御力和伤害吸收能力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 8 then
				FirstWin_Text1:SetText("供奉赫斯提亚能够提升供奉者的伤害吸收能力和闪避。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 9 then
				FirstWin_Text1:SetText("供奉波塞冬能够提升供奉者的命中和魔法攻击力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 10 then
				FirstWin_Text1:SetText("供奉阿尔忒弥斯能够提升供奉者的闪避和HP回复能力。你确定要创建这个神明的祭坛吗？");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 0 then
			        NPCFUN:EndMessage(true);
                            end;
			elseif PreSubID == 2 then  --删除祭坛
                            if SubID== 1 then
				FirstWin_Text1:SetText("你确定要删除阿波罗的祭坛吗？祭坛消失会让工会所有成员对阿波罗的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 2 then
				FirstWin_Text1:SetText("你确定要删除德墨忒耳的祭坛吗？祭坛消失会让工会所有成员对德墨忒耳的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 3 then
				FirstWin_Text1:SetText("你确定要删除赫耳墨斯的祭坛吗？祭坛消失会让工会所有成员对赫耳墨斯的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 4 then
				FirstWin_Text1:SetText("你确定要删除赫淮斯托斯的祭坛吗？祭坛消失会让工会所有成员对赫淮斯托斯的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 5 then
				FirstWin_Text1:SetText("你确定要删除哈迪斯的祭坛吗？祭坛消失会让工会所有成员对哈迪斯的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 6 then
				FirstWin_Text1:SetText("你确定要删除狄俄尼索斯的祭坛吗？祭坛消失会让工会所有成员对狄俄尼索斯的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 7 then
				FirstWin_Text1:SetText("你确定要删除阿芙洛狄忒的祭坛吗？祭坛消失会让工会所有成员对阿芙洛狄忒的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 8 then
				FirstWin_Text1:SetText("你确定要删除赫斯提亚的祭坛吗？祭坛消失会让工会所有成员对赫斯提亚的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 9 then
				FirstWin_Text1:SetText("你确定要删除波塞冬的祭坛吗？祭坛消失会让工会所有成员对波塞冬的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 10 then
				FirstWin_Text1:SetText("你确定要删除阿尔忒弥斯的祭坛吗？祭坛消失会让工会所有成员对阿尔忒弥斯的供奉失去效果！");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 0 then
			        NPCFUN:EndMessage(true);
                            end;
			elseif PreSubID == 3 then  --升级祭坛
                            if SubID== 1 then
				FirstWin_Text1:SetText("你确定要升级阿波罗的祭坛吗？升级阿波罗的祭坛可以让工会所有成员对阿波罗的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 2 then
				FirstWin_Text1:SetText("你确定要升级德墨忒耳的祭坛吗？升级德墨忒耳的祭坛可以让工会所有成员对德墨忒耳的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 3 then
				FirstWin_Text1:SetText("你确定要升级赫耳墨斯的祭坛吗？升级赫耳墨斯的祭坛可以让工会所有成员对赫耳墨斯的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 4 then
				FirstWin_Text1:SetText("你确定要升级赫淮斯托斯的祭坛吗？升级赫淮斯托斯的祭坛可以让工会所有成员对赫淮斯托斯的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 5 then
				FirstWin_Text1:SetText("你确定要升级哈迪斯的祭坛吗？升级哈迪斯的祭坛可以让工会所有成员对哈迪斯的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 6 then
				FirstWin_Text1:SetText("你确定要升级狄俄尼索斯的祭坛吗？升级狄俄尼索斯的祭坛可以让工会所有成员对狄俄尼索斯的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 7 then
				FirstWin_Text1:SetText("你确定要升级阿芙洛狄忒的祭坛吗？升级阿芙洛狄忒的祭坛可以让工会所有成员对阿芙洛狄忒的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 8 then
				FirstWin_Text1:SetText("你确定要升级赫斯提亚的祭坛吗？升级赫斯提亚的祭坛可以让工会所有成员对赫斯提亚的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 9 then
				FirstWin_Text1:SetText("你确定要升级波塞冬的祭坛吗？升级波塞冬的祭坛可以让工会所有成员对波塞冬的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 10 then
				FirstWin_Text1:SetText("你确定要升级阿尔忒弥斯的祭坛吗？升级阿尔忒弥斯的祭坛可以让工会所有成员对阿尔忒弥斯的供奉提高到一个新的境界。");
			        FirstWin_Text1:Visible(true);
			        NPCFUN:HaveMessageBox(true);
                            elseif SubID== 0 then
			        NPCFUN:EndMessage(true);
                            end;
			elseif PreSubID == 4 then  --添加供奉
                                if SubID== 1 then	
				    FirstWin_Text1:SetText("阿波罗能够提升供奉者HP和MP的最大上限。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 2 then
				    FirstWin_Text1:SetText("德墨忒耳能够提升供奉者的HP回复能力和伤害吸收能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 3 then
				    FirstWin_Text1:SetText("赫耳墨斯能够提升供奉者的MP回复能力和MP最大上限。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 4 then
				    FirstWin_Text1:SetText("赫淮斯托斯能够提升供奉者的物理攻击力和命中。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 5 then
				    FirstWin_Text1:SetText("哈迪斯能够提升供奉者的魔法攻击力和物理攻击力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 6 then
				    FirstWin_Text1:SetText("狄俄尼索斯能够提升供奉者的物理防御力和魔法防御力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 7 then
				    FirstWin_Text1:SetText("阿芙洛狄忒能够提升供奉者的魔法防御力和伤害吸收能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 8 then
				    FirstWin_Text1:SetText("赫斯提亚能够提升供奉者的伤害吸收能力和闪避。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 9 then
				    FirstWin_Text1:SetText("波塞冬能够提升供奉者的命中和魔法攻击力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 10 then
				    FirstWin_Text1:SetText("阿尔忒弥斯能够提升供奉者的闪避和HP回复能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 0 then
			            NPCFUN:EndMessage(true);
                                end;
			elseif PreSubID == 5 then  --删除供奉
                                if SubID== 1 then	
				    FirstWin_Text1:SetText("你确定要删除对阿波罗的供奉吗？小心阿波罗拿弓箭射你脚踝！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 2 then
				    FirstWin_Text1:SetText("你确定要删除对德墨忒耳的供奉吗？德墨忒耳发怒可能让你永远见不到春天！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 3 then
				    FirstWin_Text1:SetText("你确定要删除对赫耳墨斯的供奉吗？得罪赫耳墨斯可是会让你变成穷光蛋的哦！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 4 then
				    FirstWin_Text1:SetText("你确定要删除对赫淮斯托斯的供奉吗？完了，缺少赫淮斯托斯的庇护，你装备肯定会天天坏！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 5 then
				    FirstWin_Text1:SetText("你确定要删除对哈迪斯的供奉吗？哈迪斯可是很可怕的哦，难道你想提前领略地狱的风光？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 6 then
				    FirstWin_Text1:SetText("你确定要删除对狄俄尼索斯的供奉吗？很不幸的告诉你，你将会觉得喝酒还不如喝水！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 7 then
				    FirstWin_Text1:SetText("你确定要删除对阿芙洛狄忒的供奉吗？阿芙洛狄忒将会使你今后的人生远离爱情！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 8 then
				    FirstWin_Text1:SetText("你确定要删除对赫斯提亚的供奉吗？哈哈哈，以后你的家肯定天天被盗贼们光顾！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 9 then
				    FirstWin_Text1:SetText("你确定要删除对波塞冬的供奉吗？波塞冬可是宙斯的哥哥，就算你走在路上他也能淹死你！");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 10 then
				    FirstWin_Text1:SetText("你确定要删除对阿尔忒弥斯的供奉吗？额，得罪她，不好说会发生什么。真的，别问我，我真的不知道，自己摆渡去。");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 0 then
			            NPCFUN:EndMessage(true);
                                end;
			elseif PreSubID == 6 then  --升级供奉
                                if SubID== 1 then	
				    FirstWin_Text1:SetText("阿波罗能够提升供奉者HP和MP的最大上限。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 2 then
				    FirstWin_Text1:SetText("德墨忒耳能够提升供奉者的HP回复能力和伤害吸收能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 3 then
				    FirstWin_Text1:SetText("赫耳墨斯能够提升供奉者的MP回复能力和MP最大上限。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 4 then
				    FirstWin_Text1:SetText("赫淮斯托斯能够提升供奉者的物理攻击力和命中。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 5 then
				    FirstWin_Text1:SetText("哈迪斯能够提升供奉者的魔法攻击力和物理攻击力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 6 then
				    FirstWin_Text1:SetText("狄俄尼索斯能够提升供奉者的物理防御力和魔法防御力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 7 then
				    FirstWin_Text1:SetText("阿芙洛狄忒能够提升供奉者的魔法防御力和伤害吸收能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 8 then
				    FirstWin_Text1:SetText("赫斯提亚能够提升供奉者的伤害吸收能力和闪避。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 9 then
				    FirstWin_Text1:SetText("波塞冬能够提升供奉者的命中和魔法攻击力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 10 then
				    FirstWin_Text1:SetText("阿尔忒弥斯能够提升供奉者的闪避和HP回复能力。你确定要供奉这个神明吗？");
			            FirstWin_Text1:Visible(true);
			            NPCFUN:HaveMessageBox(true);
                                elseif SubID== 0 then
			            NPCFUN:EndMessage(true);
                                end;
			end;	
		end;
		
	elseif Type == NPC_FLAG_GUILDQUEST then  -------------------公会任务提示框--------------------------------------------------------------
		if SubID== 1 then
		elseif SubID== 2 then

		end;
	end;
end


--初始化UI的原始位置------------------------------------------------------------------------------------
function SetOriginalPosition()
	FirstWin_Text1:SetPosition(45,100);
	FirstWin_Text2:SetPosition(15,100);
	FirstWin_Text3:SetPosition(15,120);

	FirstWin_Button1:SetPosition(25,100);
	FirstWin_Button2:SetPosition(25,120);
	FirstWin_Button3:SetPosition(25,140);
	FirstWin_Button4:SetPosition(25,160);
	FirstWin_Button5:SetPosition(25,180);
	FirstWin_Button6:SetPosition(25,200);
	FirstWin_Button7:SetPosition(25,220);
	FirstWin_Button8:SetPosition(25,240);
	FirstWin_Button9:SetPosition(25,260);
	FirstWin_Button10:SetPosition(25,280);

	FirstWin_CheckBox1:SetPosition(45,220);
	FirstWin_CheckBox2:SetPosition(90,220);
	FirstWin_CheckBox3:SetPosition(135,220);
	FirstWin_CheckBox4:SetPosition(180,220);

	FirstWin_ButtonA1:SetPosition(145,500);
	FirstWin_ButtonA2:SetPosition(220,500);
end