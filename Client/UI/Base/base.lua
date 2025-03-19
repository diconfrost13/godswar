
--[[
	xml config 
	
	OnLoad ,     ui load,						进入主逻辑时，UI控件调用，限最上层窗体
	OnEvent ,   receive event  					控件接受消息，可以接受多消息，
	OnClick ,    button on click  					按钮左键单击事件
	OnRClick ,  button on mouse right  button click	按钮右键单击事件
	OnUpdate , on update ,						控件刷新事件，每妙30次
	OnEnter,     editor on enter,					输入框输入事件
	OnHovered, element on hovered,				控件获得焦点时间
	OnLeft, element on left					控件失去焦点事件
]]--


--[[
	UIAPI API ,

	{GetElement(id)} , return element by id				获得UI控件
	{GetElement("name")} , return element by name			获得UI控件
	{GetEvent()} , return evnet							获得消息

	{Message("string")} , message box 					通用提示框
	{"Helper" , },Helper(id? , string , element)				通用帮助提示
	{HyperLink("www.xxxx.xxx")} , HyperLink			超链接
	{"ChatMacro" }, ChatMacro("command" , "function"),	注册聊天宏

	{"AddText"} , AddText("uitemplate" , parent element),	添加Text控件
	{"AddButton"} , AddButton("uitemplate" , parent element),添加Button控件
	{"AddItem"} , AddItem("uitemplate" , parent element),	添加List item

	{"RmoveItem"} , RmoveItem(index , element);			移除List item	
	{"ClearItem"} , ClearItem(element),					清空List item
	{"Remove"} , Remove(element),						移除UI控件
	{"Release" }, Release(element),						释放UI控件
	{"ActiveList"},  ActiveList(index , element)			选中List item
	{"ActiveTab"} , ActiveTab(index  , element)			选中Tab
	{"GetActiveTab"}, GetActiveTab(element),			获得选中的Tab
	{"GetScrollPos"},  GetScrollPos(element),				获得滚动条位置0.0 - 1.0
	{"SetScrollPos"}, ,SetScrollPos(pos , element),			设置滚动条位置0.0 - 1.0

]]--


--[[
	this API , or element API this is UI last call element
	"this" is lib ,, this:Instance() is element

	{RegisterEvent(event)} , Register Event , call back function is OnEvent in xml config	注册消息
	{RegisterEvent(event,callback)} , Register Event , call back function					注册消息
	{UpdateRenderBuffer()}  , 														更新渲染队列
	{Top()} , draw front  															设置成置顶窗口

	{"IsVisible" }, IsVisible,														是否可见
	{"IsEnable" }, IsEnabled,														是否可用

	{Visible(bool)} ,																设置可见
	{Enable(bool)} ,																设置可用

	{"SetTexture(path)" },SetTexture,												设置贴图
	{"SetTexturePos(x,y)" },SetTexturePos,											设置贴图便宜
	{SetImageColor(r , g , b , a) } , set image color ,									设置贴图偏色
	{SetFontColor(r , g , b , a) } , set font color ,										设置字体偏色
	{"SetImageAlpha"},, Set Image Alpha,											设置贴图透明通道
	{"SetFontAlpha"} , Set Font Alpha,												设置字体透明通道

	{SetNumber(double) } , set number 												设置数字
	{SetText(text)}  , set text														设置字符串
	{"GetText()" }, GetText,														获得字符串

	{SetPosition(x , y)} , set position ,												设置控件位置

	{GetParent()} , return the parent													获得父控件
	{GetChild(index)},return the child , index ,,										获得子控件
	{GetChild("name")} , return the child with name									获得子控件
	{GetType} , return type															获得控件类型

	{Number() , ThisGetNumber} , get double											获得数字
	{Name() },return the name														获得控件名字
	{ID() }, return the id															获得控件ID

	{"Instance"} , this:Instance(),													获得实例

]]--


--[[
	evnet  ,

	{GetType()} , get event type														获得事件类型
	{MouseWheel()} , mouse wheel delta, usually 1,2,3,4 or -1,-2,-3,-4...					获得鼠标中键
	{MouseX()} ,  X position of mouse cursor											获得鼠标X位置
	{MouseY()} , Y position of mouse cursor											获得鼠标Y位置
	{Char()} , Key which has been pressed or released									获得键盘按下字符
	{Alt()} , true if alt was also pressed												Alt是否按下
	{Ctrl()} , true if ctrlwas also pressed												Ctrl是否按下
	{Shift()} , true if Shift was also pressed											Shift是否按下
]]--


Base = {}

local uiapi = UIAPI;
local gameapi = GameAPI;

function Base:new (o)
	o = o or {}
	setmetatable(o, self);
	self.__index = self
	return o
end

function Base:dofile (filename)
	print("Base.dofile " ..filename);
    local f = assert(loadfile(filename))
    return f()
end

function Base:Print(str)
	--gameapi:DefaultAddText(str);
end

