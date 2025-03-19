Base:dofile("./Localization/zh_cn/UI/XML/AutoFight.lua");
local auto = nil;

function SystemBar_OnLoad()

	auto = UIAPI:GetElement("AutoFightWindow");

end

function AutoFight_OnClick()
	Default_OnClick();
	auto:Visible(not auto:IsVisible());
	if auto:IsVisible() then
		auto:Top();
	end
end

function AutoFightButton_OnUpdate()
	AutoFight_OnUpdate();
end

function F12_OnClick()
	AutoRun_OnClick();
end
