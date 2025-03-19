--Revive.lua--死亡复活说明文本----------------------

local MSG_Revive = {};
MSG_Revive.msg1 = "你已经死了哇！";
MSG_Revive.msg2 = "死神塔那托斯收起了他的镰刃，你还在犹豫什么……";
MSG_Revive.msg3 = "倒下了，但是你能感受到地母盖亚传输来的能量。";
MSG_Revive.msg4 = "阿波罗在你的头发中种了一根不死的金发，不过它现在脱落了。";
MSG_Revive.msg5 = "英雄俄尔浦斯哀婉的琴音和歌声在你身边萦绕。";
MSG_Revive.msg6 = "忒提斯女神悄悄地往你身上洒了一些冥狱守誓之河斯提克斯的水……";
MSG_Revive.msg7 = "阿斯克勒庇俄斯似乎曾经教过我自救的方法。";
MSG_Revive.msg8 = "贤师喀戎似乎曾经教过我自救的方法。";
MSG_Revive.msg9 = "卡德摩斯英雄家族的血液在我身上流淌……";
MSG_Revive.msg10 = "你在黄泉的路上朝着人间呼喊：I will be back!";
MSG_Revive.msg11 = "难道，诸神要把死后的我发配到流放之地塔尔塔罗斯吗？";
MSG_Revive.msg12 = "冥界的通路还没有打开，你在沉睡中恍惚听见三头地狱犬刻耳柏洛斯的狂吠声……";
MSG_Revive.msg13 = "拉达曼提斯说你无法进入英灵乐土爱丽舍，世间的伙伴还在召唤着你。";
MSG_Revive.msg14 = "燃烧吧！我的小宇宙……";
MSG_Revive.msg15 = "重伤昏厥了。我梦见了战争中的阿瑞斯与雅典娜，我还要为我的信仰而战。";
MSG_Revive.msg16 = "命运女神给了你一次复活的机会。";
MSG_Revive.msg17 = "濒死状态中，我领悟了第七感。";
MSG_Revive.msg18 = "难道以后再也见不到海伦和美狄亚了吗？";
MSG_Revive.msg19 = "英雄柏勒罗丰曾经说道，宙斯的雷霆也无法阻挡我的意志。";
MSG_Revive.msg20 = "我可不愿意现在就下去见赫拉克勒斯，故去的他一定会在冥府嘲笑我的。";
MSG_Revive.msg21 = "安德洛美达公主的灵魂与我同在，她赠予我一根凤凰羽毛。";
MSG_Revive.msg22 = "奥林匹斯圣山的雪在融化，难道我的肉身也要融化了么……";
MSG_Revive.msg23 = "还要活着去特洛伊和吕基亚诸城邦所在的小亚细亚……尽管腿脚已经不听使唤。";
MSG_Revive.msg24 = "英雄奥德修斯曾邀请我去桃源仙境伊塔刻岛呢，不可以在这里倒下。";
MSG_Revive.msg25 = "我的灵魂何时能飘荡到埃及，重走那泰坦之旅。奥西里斯神大概不会欢迎我吧。";
MSG_Revive.msg26 = "圣城德尔斐的佩提亚先知们在为我祈祷……";
MSG_Revive.msg27 = "奥林匹亚的圣火还在燃烧，我的生命也将被光明点燃。";

MSG_Revive.msg50 = "没有足够的金币！原地复活需要";
MSG_Revive.msg51 = "金币";
MSG_Revive.msg52 = "原地复活消耗";
MSG_Revive.msg53 = "金币！";
MSG_Revive.msg54 = "恢复100%的HP与MP";
MSG_Revive.msg55 = "没有足够的银币!原地复活需要";
MSG_Revive.msg56 = "银币";
MSG_Revive.msg57 = "银币！";
MSG_Revive.msg58 = "恢复30%的HP与MP";
MSG_Revive.msg59 = "您将返回附近城镇";
MSG_Revive.msg60 = "秒后复活！";

function Get_Revive_Msg(text)
	return MSG_Revive[text];
end
