--message config

local uiapi = UIAPI

function Message(msg)
	print(msg)
	uiapi:Message(msg);
end

--local count = 0;

--function Message_OnClick()
--	count = count + 1;
--	print(count);
	--uiapi:HyperLink("www.sina.com.cn");
--	Message("left click");
--end

--function Message_OnRClick()
--	uiapi:HyperLink("www.163.com");
--	Message("right click");
--end

function Message_OnEvent()

	local event = uiapi:GetEvent();
	local type = event:GetType();
	local b = event:Alt();
	print( b , type);	

	if type == EVENT.GAME.DAMAGE then
		local win = uiapi:GetElement(1);
		--win:UpdateDrawBuffer();
		local text =  win:GetChild("Text");
		--text:SetPosition(100 , 3);
		--text:SetVisible(true);
		text:SetFontColor(255,255 , 0 ,255);
		text:SetText("很强大！！");
	end
	
end

function Message_Onload()
	this:RegisterEvent(EVENT.GAME.DAMAGE);
	print(this:Name());
end


