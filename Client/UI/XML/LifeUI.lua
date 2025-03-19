local uiapi=UIAPI
local win = nil;

--初始化各个控件
function LifeUI_OnLoad()     
	win = uiapi:GetElement("LifeUI");	

	win:UpdateRenderBuffer();
end

--设置帮助窗体是否可见
function LifeUI_OnSetVisble()
	win:Visible(not win:IsVisible());
end
