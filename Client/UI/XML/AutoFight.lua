local first_open = true;

local win = nil;

local filtration = nil;

--local auto_checkbox = nil;
local skill_checkbox = nil;
local attack_checkbox = nil;
local HP_checkbox = nil;
local MP_checkbox = nil;
local HP_edit = nil;
local MP_edit = nil;
local red_checkbox = nil;
local blue_checkbox = nil;




local minhp = 6;
local minhp_temp = 6;
local minmp = 4;
local minmp_temp = 4;
--local autorun = false;
--local autorun_temp = false;
local autoskill = false;
local autoskill_temp = false;
local autoattack = false;
local autoattack_temp = false;
local autored = false;
local autored_temp = false;
local autoblue = false;
local autoblue_temp = false;
local redleave = false;
local redleave_temp = false;
local blueleave = false;
local blueleave_temp = false;


function AutoFight_OnLoad()

	win = this:Instance();

	filtration = UIAPI:GetElement("Filtration");
	
	
	--auto_checkbox = this:GetChild("checkboxautorun");
	skill_checkbox = this:GetChild("checkboxuseskill");
	attack_checkbox = this:GetChild("checkboxautofight");
	HP_checkbox = this:GetChild("checkboxhp");
	MP_checkbox = this:GetChild("checkboxmp");
	HP_edit = this:GetChild("edithp");
	MP_edit = this:GetChild("editmp");
	red_checkbox = this:GetChild("checkboxred");
	blue_checkbox = this:GetChild("checkboxblue");
end


function AutoFight_OnUpdate()
	if AutoFightAPI:IsRunAutoFight() then
		hp = PlayerAPI:GetGameData():GetSelfHP();
		mp = PlayerAPI:GetGameData():GetSelfMP();
	
		if minhp*10 > hp and autored then
		--hp low
			AutoFightAPI:UseRemedy(1);
		end
	
		if minmp*10 > mp and autoblue then
		--mp low	
			AutoFightAPI:UseRemedy(2);
		end
	end
	
	
--[[	text:SetText("HP:"..hp.."%\n".."MP:"..mp.."%\n");

	if minhp > hp then
		--hp low
		
		text:SetText("hp low");
	end
	
	if minmp > mp then
		--mp low
		
		text:SetText("mp low");
	end
]]--
end

function AutoFight_OnEnterHp()
	minhp_temp = this:Number();
end

function AutoFight_OnEnterMp()
	minmp_temp = this:Number();
end

function Filtration_OnClick()
	filtration:Visible(not filtration:IsVisible());
end

function AutoRun_OnClick()
	if first_open then
	AutoInit();
	end
	if win:IsVisible() then
--	Default_OnClick();
	SaveSetting_OnClick();
	end
	AutoFightAPI:AutoRunSwitch(true);
	win:Visible(false);
end

function AutoSkill_OnClick()
	autoskill_temp = UIAPI:IsChecked(this:Instance());
end

function AutoAttack_OnClick()
	autoattack_temp = UIAPI:IsChecked(this:Instance());
end

function RedRemedy_OnClick()
	autored_temp = UIAPI:IsChecked(this:Instance());
	--[[AutoFightAPI:UseRemedy(1);]]--
end

function BlueRemedy_OnClick()
	autoblue_temp = UIAPI:IsChecked(this:Instance());
	--[[AutoFightAPI:UseRemedy(2);]]--
end

function RedLeave_OnClick()
	redleave_temp = UIAPI:IsChecked(this:Instance());
	--[[AutoFightAPI:UseRemedy(1);]]--
end

function BlueLeave_OnClick()
	blueleave_temp = UIAPI:IsChecked(this:Instance());
	--[[AutoFightAPI:UseRemedy(2);]]--
end

function SaveSetting_OnClick()
--	autorun_temp = UIAPI:IsChecked(auto_checkbox);
	minhp = minhp_temp;
	minmp = minmp_temp;
--	autorun = autorun_temp;
	autoskill = autoskill_temp;
	autoattack = autoattack_temp;
	autored = autored_temp;
	autoblue = autoblue_temp;
	redleave = redleave_temp;
	blueleave = blueleave_temp;

--	AutoFightAPI:AutoRunSwitch(autorun);
	AutoFightAPI:AutoSkillSwitch(autoskill);
	AutoFightAPI:AutoAttackSwitch(autoattack);
	AutoFightAPI:RedLeaveSwitch(redleave);
	AutoFightAPI:BlueLeaveSwitch(blueleave);
	
end

function Default_OnClick()
--	autorun_temp = AutoFightAPI:IsRunAutoFight();
--	autorun = autorun_temp;
	if not first_open then
--		UIAPI:SetChecked(autorun,auto_checkbox);
--		autorun_temp = autorun;
		UIAPI:SetChecked(autoskill,skill_checkbox);
		autoskill_temp = autoskill;
		UIAPI:SetChecked(autoattack,attack_checkbox);
		autoattack_temp = autoattack;
		UIAPI:SetChecked(autored,HP_checkbox);
		autored_temp = autored;
		UIAPI:SetChecked(autoblue,MP_checkbox);
		autoblue_temp = autoblue;
		UIAPI:SetChecked(redleave,red_checkbox);
		redleave_temp = redleave;
		UIAPI:SetChecked(blueleave,blue_checkbox);
		blueleave_temp = blueleave;
		HP_edit:SetText(minhp);
		minhp_temp = minhp;
		MP_edit:SetText(minmp);
		minmp_temp = minmp;
	else
--		autorun_temp = UIAPI:IsChecked(auto_checkbox);
--		autorun = autorun_temp;
		AutoInit();	
	end
end

function AutoInit()
	autoskill_temp = UIAPI:IsChecked(skill_checkbox);
	autoskill = autoskill_temp;
	autoattack_temp = UIAPI:IsChecked(attack_checkbox);
	autoattack = autoattack_temp;
	autored_temp = UIAPI:IsChecked(HP_checkbox);
	autored = autored_temp;
	autoblue_temp = UIAPI:IsChecked(MP_checkbox);
	autoblue = autoblue_temp;
	redleave_temp = UIAPI:IsChecked(red_checkbox);
	redleave = redleave_temp;
	blueleave_temp = UIAPI:IsChecked(blue_checkbox);
	blueleave = blueleave_temp;

	if HP_edit:Number()>0 then
	minhp_temp = HP_edit:Number();
	minhp = minhp_temp;
	else
	HP_edit:SetText(minhp);
	end
	if MP_edit:Number()>0 then
	minmp_temp = MP_edit:Number();
	minmp = minmp_temp;
	else
	MP_edit:SetText(minmp);
	end

	AutoFightAPI:AutoSkillSwitch(autoskill);
	AutoFightAPI:AutoAttackSwitch(autoattack);
	AutoFightAPI:RedLeaveSwitch(redleave);
	AutoFightAPI:BlueLeaveSwitch(blueleave);
	first_open = false;
end





