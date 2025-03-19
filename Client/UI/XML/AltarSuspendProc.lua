--2008.09.23 tavia
--祭坛悬停的函数处理---
-------变量的声明

local uiapi=UIAPI
--这个值可能会变。所有定义成宏
local MAXLEVEL=12;

function AltarSuspend_Hovered(textID)

	altar_id=0;
	altar_lev=0;
	play_lev=0;
	
	altar_id,altar_lev,play_lev=GameAPI:GetAltarInfo(textID);
	
	altar_lev_next=altar_lev+1;
	play_lev_next=play_lev+1;
	
	--祭坛种类的配置
	t_sort=Get_AltarSuspend_Cofig(altar_id);	
	if t_sort == nil then
		return;
	end
	--祭坛等级的配置
	t_lev_next=Get_AltarSuspend_Level(altar_lev+1);
	--个人升级祭坛需要的供奉
	t_play_lev_next=Get_AltarSuspend_Level(play_lev+1);	
	
	--祭坛的名字
	allStr=t_sort.Name.."\n";	
	--祭坛的等级
	allStr=allStr..ASP_L0_1..altar_lev.."\n";
	--效果
	eff1="Effect1_Level"..altar_lev;
	eff2="Effect2_Level"..altar_lev;
	
	allStr=allStr.."|cffffff00"..t_sort.Effect1.."+"..t_sort[eff1].."，"..t_sort.Effect2.."+"..t_sort[eff2].."|cffffffff".."\n";
	--allStr=allStr..t_sort.Effect2.."+"..t_sort[eff2].."\n";
	
	if altar_lev < MAXLEVEL then	
		--下一等级
		allStr=allStr..ASP_L0_2.."\n";
		--效果
		eff1_next="Effect1_Level"..altar_lev_next;
		eff2_next="Effect2_Level"..altar_lev_next;
		
		allStr=allStr.."|cffffff00"..t_sort.Effect1.."+"..t_sort[eff1_next]..","..t_sort.Effect2.."+"..t_sort[eff2_next].."|cffffffff".."\n";
		--allStr=allStr..t_sort.Effect2.."+"..t_sort[eff2_next].."\n";
		--升级需公会银币OO公会金币XX
		allStr=allStr..ASP_L0_3..t_lev_next.Found..ASP_L0_4..t_lev_next.Bijou.."\n\n";
	else
		allStr=allStr..ASP_L0_5.."\n\n";	
	end
	
	--你当前供奉等级：1/5
	allStr=allStr..ASP_L0_6..play_lev.."/"..altar_lev.."\n";
	if play_lev == 0 then
		--个人效果
		eff1="Effect1_Level"..play_lev;
		eff2="Effect2_Level"..play_lev;
		
		allStr=allStr.."|cffffff00"..t_sort.Effect1.."+".."0".."，"..t_sort.Effect2.."+".."0".."|cffffffff".."\n";
		--allStr=allStr..t_sort.Effect2.."+".."0".."\n";		
	else
		--个人效果
		eff1="Effect1_Level"..play_lev;
		eff2="Effect2_Level"..play_lev;
		
		allStr=allStr.."|cffffff00"..t_sort.Effect1.."+"..t_sort[eff1].."，"..t_sort.Effect2.."+"..t_sort[eff2].."|cffffffff".."\n";
		--allStr=allStr..t_sort.Effect2.."+"..t_sort[eff2].."\n";
	end
	
	if play_lev < altar_lev then
		--个人下一等级
		allStr=allStr..ASP_L0_2.."\n";
		--个人效果
		eff1_next="Effect1_Level"..play_lev_next;
		eff2_next="Effect2_Level"..play_lev_next;
		
		allStr=allStr.."|cffffff00"..t_sort.Effect1.."+"..t_sort[eff1_next].."，"..t_sort.Effect2.."+"..t_sort[eff2_next].."|cffffffff".."\n";
		--allStr=allStr..t_sort.Effect2.."+"..t_sort[eff2_next].."\n";
		
		--升级供奉需个人贡献
		allStr=allStr..ASP_L0_7..t_play_lev_next.Contribute;
	else
		allStr=allStr..ASP_L0_8.."\n";		
	end
	uiapi:Helper(false,allStr,this:Instance());
	
end

function AltarSuspend_Left()

	uiapi:Helper(false,"",this:Instance());
	
end


