-- this is font config 


--freetypefont	
	local	GUIFTF_NORMAL = 0;
	local 	GUIFTF_CENTER = 1;
	local	GUIFTF_RIGHT = 2;
	local	GUIFTF_VCENTER = 4;
	local	GUITTF_BOTTOM = 8;
	local	GUIFTF_WORDBREAK = 16;

--TextWeight
	local	GUIFTW_NONE = 0;
	local	GUIFTW_THIN = 1;
	local	GUIFTW_NORMAL = 2;
	local	GUIFTW_BOLD = 3;

font = {}



--Normal

  --主界面字体    
	MainFonts	= {name="雅黑12号",  path="./Fonts/MainFont.ttf",	size=12 , flag=11012} 
	Mainlogin2	= {name="雅黑14号",  path="./Fonts/MainFont.ttf",	size=14 , flag=11014}  
	MainMap	        = {name="雅黑10号",  path="./Fonts/MainFont.ttf",	size=10 , flag=11016}  
	Mainlogin	= {name="雅黑16号",  path="./Fonts/MainFont.ttf",	size=16 , flag=11018}
        MainFonts2	= {name="雅黑12号",  path="./Fonts/MainFont.ttf",	size=18 , flag=11017}

      


	
  --聊天字体
	ChatFont14	= {name="宋体12号",  path="./Fonts/ChatFont.ttf",	size=10 , flag=12014}

  --消息字体
	MessageFont24	= {name="宋体12号",  path="./Fonts/MessageFont.ttf",	size=24 , flag=13024}

  --战斗字体
	FightFont24	= {name="宋体12号",  path="./Fonts/FightFont.ttf",	size=18 , flag=14024}
	

--Container  
  
	con_MainFont12	= {name="容器名12号", path="./Fonts/MainFont.ttf", 	size=12 , flag=21014} 
	
	CONTAIN1_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21001 }
	CONTAIN2_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21002 }
	CONTAIN3_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21003 }
	CONTAIN4_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21004 }
	CONTAIN5_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21005 }
	CONTAIN6_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=10 , flag = 21006 }
	CONTAIN7_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=12 , flag = 21007}
	CONTAIN8_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=12 , flag = 21009 }
	
	CONTAIN9_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",		size=12 , flag = 21011}
	CONTAIN10_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",	size=12 , flag = 21012}
	CONTAIN11_BILLBOARD = {name="宋体" , path="./Fonts/MainFont.ttf",	size=10 , flag = 21013}
	
	CONTAIN_Mall_TEXTFONT = {name="宋体" , path="./Fonts/MainFont.ttf",	size=12 , flag = 21010 }



--color
DEFAULT_TEXTCOLOR       = {r=255 , g=255 , b=255 , a=255}
YELLOW_TEXTCOLOR = {r=255 , g=255 , b=0 , a=255}
GREEN_TEXTCOLOR = {r=0 , g=255 , b=0 , a=255}
LoginEdit_TEXTCOLOR = { r=205 , g=205, b=205, a=255 }  
TEST_IMAGECOLOR = {r=255 , g=0 , b=0 , a=255}
GWO_IMG_TEXTCOLOR = {r=232, g=191, b=0, a=255}
BASE_HEADCOLOR = {r=107 , g=204 , b=254 , a=255}
ORDINARY_INFOCOLOR = {r=255 , g=247 , b=124 , a=255}
WHISPER_COLOR = {r=255 , g=134, b=238,a=255}
TEAM_COLOR= {r=0, g=252 , b=237,a=255 }
GUILD_COLOR = {r=255 , g=153 , b=0,a=255}
CAMP_COLOR={r=30, g=254, b=0,a=255 }
BillBoard_TEXTCOLOR = {r=240 , g=195, b=0,a=255}
GWORed		= {r=255, g=0  , b=0  , a=255}


