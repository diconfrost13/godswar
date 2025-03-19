print("Reveve Inin Success!!!");

Base:dofile("./UI/XML/Message.lua");

local REVIVE_STONE    = 0;
local REVIVE_MONEY    = 1;
local REVIVE_FREE     = 2;

local Stone_Consume = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		       1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		       2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,
		       6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
		       7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,12};

local Money_Consume = {280,280,280,280,280,280,280,280,280,280,450,450,450,450,450,450,450,450,450,450,650,650,650,650,650,650,650,650,650,650,820,820,820,820,820,820,820,820,820,820,
		       1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1660,1660,1660,1660,1660,1660,1660,1660,1660,1660,2080,2080,2080,2080,2080,2080,2080,2080,2080,2080,2500,2500,2500,2500,2500,2500,2500,2500,2500,2500,
		       2920,2920,2920,2920,2920,2920,2920,2920,2920,2920,3340,3340,3340,3340,3340,3340,3340,3340,3340,3340,3760,3760,3760,3760,3760,3760,3760,3760,3760,3760,4180,4180,4180,4180,4180,4180,4180,4180,4180,4180,
		       4600,4600,4600,4600,4600,4600,4600,4600,4600,4600,5020,5020,5020,5020,5020,5020,5020,5020,5020,5020,5440,5440,5440,5440,5440,5440,5440,5440,5440,5440,5860,5860,5860,5860,5860,5860,5860,5860,5860,5860,
		       6280,6280,6280,6280,6280,6280,6280,6280,6280,6280,6700,6700,6700,6700,6700,6700,6700,6700,6700,6700,7120,7120,7120,7120,7120,7120,7120,7120,7120,7120,7540,7540,7540,7540,7540,7540,7540,7540,7540,7540};

local ReviveBGWin = UIAPI:GetElement("ReviveBGWin");
local ReviveWin = ReviveBGWin:GetChild("ReviveWin");
local Revive_Text = ReviveWin:GetChild("Revive_Text");
local ReviveBtn_Confirm = ReviveWin:GetChild("ReviveBtn_Confirm");
local ReviveBtn_Cancel= ReviveWin:GetChild("ReviveBtn_Cancel");
local ReviveBtn_Stone = ReviveWin:GetChild("ReviveBtn_Stone");
local ReviveBtn_Money = ReviveWin:GetChild("ReviveBtn_Money");
local ReviveBtn_Free = ReviveWin:GetChild("ReviveBtn_Free");


function Revive_Init()

	Revive_Text:Visible(true);
	ReviveBtn_Confirm:Visible(false);
	ReviveBtn_Cancel:Visible(false);
	ReviveBtn_Stone:Visible(false);
	ReviveBtn_Money:Visible(false);
	ReviveBtn_Free:Visible(true);
	local msg_ID = math.random(1,27);
	local msg_text = "msg" .. msg_ID;
	Revive_Text:SetText(Get_Revive_Msg(msg_text));
end


function OnClick_ReviveBtn_Stone()
	print(PlayerAPI:GetStone());
	print(Stone_Consume[PlayerAPI:GetRank()]);
	if PlayerAPI:GetStone() < Stone_Consume[PlayerAPI:GetRank()] then
		local text = Get_Revive_Msg("msg50") .. Stone_Consume[PlayerAPI:GetRank()] .. Get_Revive_Msg("msg51");
		Revive_Text:SetText(text);
	else
		ReviveBtn_Confirm:Visible(true);
		ReviveBtn_Cancel:Visible(true);
		ReviveBtn_Stone:Visible(false);
		ReviveBtn_Money:Visible(false);
		ReviveBtn_Free:Visible(false);

		local text = Get_Revive_Msg("msg52") .. Stone_Consume[PlayerAPI:GetRank()] .. Get_Revive_Msg("msg53") .. Get_Revive_Msg("msg54");
		Revive_Text:SetText(text);
		Revive:SetReviveType(REVIVE_STONE);
	end;
end

function OnClick_ReviveBtn_Money()
	print(PlayerAPI:GetMoney());
	print(Money_Consume[PlayerAPI:GetRank()]);
	if PlayerAPI:GetMoney() < Money_Consume[PlayerAPI:GetRank()] then
		local text = Get_Revive_Msg("msg55") .. Money_Consume[PlayerAPI:GetRank()] .. Get_Revive_Msg("msg56");
		Revive_Text:SetText(text);
	else
		ReviveBtn_Confirm:Visible(true);
		ReviveBtn_Cancel:Visible(true);
		ReviveBtn_Stone:Visible(false);
		ReviveBtn_Money:Visible(false);
		ReviveBtn_Free:Visible(false);

		local text = Get_Revive_Msg("msg52") .. Money_Consume[PlayerAPI:GetRank()] .. Get_Revive_Msg("msg57") .. Get_Revive_Msg("msg58");
		Revive_Text:SetText(text);
		Revive:SetReviveType(REVIVE_MONEY);
	end;
end

function OnClick_ReviveBtn_Free()
	ReviveBtn_Confirm:Visible(true);
	ReviveBtn_Cancel:Visible(true);
	ReviveBtn_Stone:Visible(false);
	ReviveBtn_Money:Visible(false);
	ReviveBtn_Free:Visible(false);
	Revive_Text:SetText(Get_Revive_Msg("msg59"));

	Revive:SetReviveType(REVIVE_FREE);
end

function OnClick_Confirm()
	ReviveBtn_Confirm:Visible(false);
	ReviveBtn_Cancel:Visible(false);
	ReviveBtn_Stone:Visible(false);
	ReviveBtn_Money:Visible(false);
	ReviveBtn_Free:Visible(false);
	
	Revive:TimeStart();
end

function OnClick_Cancel()
	Revive:TimeEnd();
	Revive_Init();
end

function Updata_ReviveTime(time)
	local text = time .. Get_Revive_Msg("msg60");
	Revive_Text:SetText(text);
end
