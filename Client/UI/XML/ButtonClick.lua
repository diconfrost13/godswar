print("ButtonClick Init Success!!!");

local uiapi=UIAPI

function UpListBoxBtn()

	local scroll = this:GetParent():GetChild("ListBox"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos-0.1,scroll);
end

function DownListBoxBtn()

	local scroll = this:GetParent():GetChild("ListBox"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos+0.1,scroll);
end


function UpContainerBtn()

	local scroll = this:GetParent():GetChild("Container"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos-0.1,scroll);
end

function DownContainerBtn()

	local scroll = this:GetParent():GetChild("Container"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos+0.1,scroll);
end


function UpContainer1Btn()

	local scroll = this:GetParent():GetChild("Container1"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos-0.1,scroll);
end

function DownContainer1Btn()

	local scroll = this:GetParent():GetChild("Container1"):GetChild(0);
	local pos = uiapi:GetScrollPos(scroll);
	uiapi:SetScrollPos(pos+0.1,scroll);
end