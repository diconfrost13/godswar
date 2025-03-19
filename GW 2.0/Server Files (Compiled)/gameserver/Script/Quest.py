# import item,, improt time
import Item
# SpecialFlags
QUEST_SPECIAL_FLAGS_NONE = 0
QUEST_SPECIAL_FLAGS_DELIVER = 1
QUEST_SPECIAL_FLAGS_MAP_EXPLORER = 2
QUEST_SPECIAL_FLAGS_SPEAKTO = 4
QUEST_SPECIAL_FLAGS_KILL_OR_CAST = 8
QUEST_SPECIAL_FLAGS_TIMED = 16
QUEST_SPECIAL_FLAGS_REPEATABLE = 32
QUEST_SPECIAL_FLAGS_REPUTATION = 64
QUEST_SPECIAL_FLAGS_LOOP = 128
# QuestSort
QUEST_SORT_STORY = 0
QUEST_SORT_STORIES = 1
QUEST_SORT_REWARD = 2
QUEST_SORT_CLASS = 3
QUEST_SORT_FACTION = 4
QUEST_SORT_DAYS = 5
QUEST_SORT_LOOP = 6
QUEST_SORT_RANDOM = 7
QUEST_SORT_Consortia = 8
# QuestColor
COLOR_WHITE = 0
COLOR_GREEN = 1
COLOR_BLUE = 2
COLOR_PURPLE = 3
# QuestFaction
QUEST_FACTION_NONE = -1
QUEST_FACTION_Q_Athens = 0
QUEST_FACTION_Q_Sparta = 1
# QuestClass
QUEST_CLASS_NONE = -1
QUEST_CLASS_FIGHTER = 4
QUEST_CLASS_SCHOLAR = 5
QUEST_CLASS_FIGHTER1 = 0
QUEST_CLASS_FIGHTER2 = 1
QUEST_CLASS_SCHOLAR1 = 2
QUEST_CLASS_SCHOLAR2 = 3
# QuestBelief
QUEST_BELIEF_NONE = -1
class QuestInfo:
    def __init__(self):
        self.QuestID = -1
        self.QuestSort = 0
        self.PrevQuestId = -1
        self.NextQuestId = -1
        self.NextQuestsId = -1 , -1
        self.TeamLimit = -1
        self.MinLevel = 1
        self.MaxLevel = 200
        self.RequiredClass = -1
        self.RequiredBelief = -1
        self.RequiredFaction = -1
        self.RequiredLevel = -1
        self.MinTime = [0,58,0,-1]  #hour(0-23),min(0-59),sec(0-59),wday(0-6)
        self.MaxTime = [18,16,0,-1] #hour(0-23),min(0-59),sec(0-59),wday(0-6)
        self.MaxNum = 0
        self.SpecialFlags = QUEST_SPECIAL_FLAGS_NONE
        self.Color = COLOR_WHITE
        self.Item = [-1 , -1 , -1 , -1]
        self.Creature = [-1 , -1 , -1 , -1]
        self.ItemCount = [0 , 0 , 0 , 0]
        self.CreatureCount = [0 , 0 , 0 , 0]
        self.ItemProbability = [100 , 100 , 100 , 100]
        self.ExplorerMapID =-1
        self.ExplorerMapPosition =-1,-1
        self.Money = 0
        self.Bijou = 0
        self.Repeat = 1
        self.RewardMoney = 0
        self.RewardBijou = 0
        self.RewardItem = [Item.ItemData() , Item.ItemData() , Item.ItemData(),Item.ItemData()]
        self.RewardUionBijou = 0
        self.RewardUionMoney = 0
        self.ReqConsortiaLV = 0
    def __del__(self):
        return 0
class QuestReward:
    def __init__(self):
        self.QuestID = -1
        self.Credit = 0
        self.Contribute = 0
        self.EXP = 0
        self.SkillPoint = 0
        self.SpecialFlags = 0
        self.SpecialCount = 0
        self.UionContribute = 0
    def __del__(self):
        return 0
#########################
QI1000 = QuestInfo()
QI1001 = QuestInfo()
QI1002 = QuestInfo()
QI1003 = QuestInfo()
QI1004 = QuestInfo()
QI1005 = QuestInfo()
QI1006 = QuestInfo()
QI1007 = QuestInfo()
QI1008 = QuestInfo()
QI1009 = QuestInfo()
QI1010 = QuestInfo()
QI1011 = QuestInfo()
QI1012 = QuestInfo()
QI1013 = QuestInfo()
QI1014 = QuestInfo()
QI1015 = QuestInfo()
QI1016 = QuestInfo()
QI1017 = QuestInfo()
QI1018 = QuestInfo()
QI1019 = QuestInfo()
QI1020 = QuestInfo()
QI1021 = QuestInfo()
QI1022 = QuestInfo()
QI1023 = QuestInfo()
QI1024 = QuestInfo()
QI1025 = QuestInfo()
QI1026 = QuestInfo()
QI1027 = QuestInfo()
QI1028 = QuestInfo()
QI1029 = QuestInfo()
QI1030 = QuestInfo()
QI1031 = QuestInfo()
QI1032 = QuestInfo()
QI1033 = QuestInfo()
QI1034 = QuestInfo()
QI1035 = QuestInfo()
QI1036 = QuestInfo()
QI1037 = QuestInfo()
QI1038 = QuestInfo()
QI1039 = QuestInfo()
QI1040 = QuestInfo()
QI1041 = QuestInfo()
QI1042 = QuestInfo()
QI1043 = QuestInfo()
QI1044 = QuestInfo()
QI1045 = QuestInfo()
QI1046 = QuestInfo()
QI1047 = QuestInfo()
QI1048 = QuestInfo()
QI1049 = QuestInfo()
QI1050 = QuestInfo()
QI1051 = QuestInfo()
QI1052 = QuestInfo()
QI1053 = QuestInfo()
QI1054 = QuestInfo()
QI1055 = QuestInfo()
QI1056 = QuestInfo()
QI1057 = QuestInfo()
QI1058 = QuestInfo()
QI1059 = QuestInfo()
QI1060 = QuestInfo()
QI1061 = QuestInfo()
QI1062 = QuestInfo()
QI1063 = QuestInfo()
QI1064 = QuestInfo()
QI1065 = QuestInfo()
QI1066 = QuestInfo()
QI1067 = QuestInfo()
QI1068 = QuestInfo()
QI1069 = QuestInfo()
QI1070 = QuestInfo()
QI1071 = QuestInfo()
QI1072 = QuestInfo()
QI1073 = QuestInfo()
QI1074 = QuestInfo()
QI1075 = QuestInfo()
QI1076 = QuestInfo()
QI1077 = QuestInfo()
QI1078 = QuestInfo()
QI1079 = QuestInfo()
QI1080 = QuestInfo()
QI1081 = QuestInfo()
QI1082 = QuestInfo()
QI1083 = QuestInfo()
QI1084 = QuestInfo()
QI1085 = QuestInfo()
QI1086 = QuestInfo()
QI1087 = QuestInfo()
QI1088 = QuestInfo()
QI1089 = QuestInfo()
QI1090 = QuestInfo()
QI1091 = QuestInfo()
QI1092 = QuestInfo()
QI1093 = QuestInfo()
QI1094 = QuestInfo()
QI1095 = QuestInfo()
QI1096 = QuestInfo()
QI1097 = QuestInfo()
QI1098 = QuestInfo()
QI1099 = QuestInfo()
QI1100 = QuestInfo()
QI1101 = QuestInfo()
QI1102 = QuestInfo()
QI1103 = QuestInfo()
QI1104 = QuestInfo()
QI1105 = QuestInfo()
QI1106 = QuestInfo()
QI1107 = QuestInfo()
QI1108 = QuestInfo()
QI1109 = QuestInfo()
QI1110 = QuestInfo()
QI1111 = QuestInfo()
QI1112 = QuestInfo()
QI1113 = QuestInfo()
QI1114 = QuestInfo()
QI1115 = QuestInfo()
QI1116 = QuestInfo()
QI1117 = QuestInfo()
QI1118 = QuestInfo()
QI1119 = QuestInfo()
QI1120 = QuestInfo()
QI1121 = QuestInfo()
QI1122 = QuestInfo()
QI1123 = QuestInfo()
QI1124 = QuestInfo()
QI1125 = QuestInfo()
QI1126 = QuestInfo()
QI1127 = QuestInfo()
QI1128 = QuestInfo()
QI1129 = QuestInfo()
QI1130 = QuestInfo()
QI1131 = QuestInfo()
QI1132 = QuestInfo()
QI1133 = QuestInfo()
QI1134 = QuestInfo()
QI1135 = QuestInfo()
QI1136 = QuestInfo()
QI1137 = QuestInfo()
QI1138 = QuestInfo()
QI1139 = QuestInfo()
QI1140 = QuestInfo()
QI1141 = QuestInfo()
QI1142 = QuestInfo()
QI1143 = QuestInfo()
QI1144 = QuestInfo()
QI1145 = QuestInfo()
QI1146 = QuestInfo()
QI1147 = QuestInfo()
QI1148 = QuestInfo()
QI1149 = QuestInfo()
QI1150 = QuestInfo()
QI1151 = QuestInfo()
QI1152 = QuestInfo()
QI1153 = QuestInfo()
QI1154 = QuestInfo()
QI1155 = QuestInfo()
QI1156 = QuestInfo()
QI1157 = QuestInfo()
QI1158 = QuestInfo()
QI1159 = QuestInfo()
QI1160 = QuestInfo()
QI1161 = QuestInfo()
QI1162 = QuestInfo()
QI1163 = QuestInfo()
QI1164 = QuestInfo()
QI1165 = QuestInfo()
QI1166 = QuestInfo()
QI1167 = QuestInfo()
QI1168 = QuestInfo()
QI1169 = QuestInfo()
QI1170 = QuestInfo()
QI1171 = QuestInfo()
QI1172 = QuestInfo()
QI1173 = QuestInfo()
QI1174 = QuestInfo()
QI1175 = QuestInfo()
QI1176 = QuestInfo()
QI1177 = QuestInfo()
QI1178 = QuestInfo()
QI1179 = QuestInfo()
QI1180 = QuestInfo()
QI1181 = QuestInfo()
QI1182 = QuestInfo()
QI1183 = QuestInfo()
QI1184 = QuestInfo()
QI1185 = QuestInfo()
QI1186 = QuestInfo()
QI1187 = QuestInfo()
QI1207 = QuestInfo()
QI1208 = QuestInfo()
QI1209 = QuestInfo()
QI1223 = QuestInfo()
QI1224 = QuestInfo()
QI1225 = QuestInfo()
QI1226 = QuestInfo()
QI1210 = QuestInfo()
QI1211 = QuestInfo()
QI1212 = QuestInfo()
QI1227 = QuestInfo()
QI1228 = QuestInfo()
QI1229 = QuestInfo()
QI1230 = QuestInfo()
QI1188 = QuestInfo()
QI1189 = QuestInfo()
QI1190 = QuestInfo()
QI1191 = QuestInfo()
QI1197 = QuestInfo()
QI1198 = QuestInfo()
QI1199 = QuestInfo()
QI1192 = QuestInfo()
QI1193 = QuestInfo()
QI1194 = QuestInfo()
QI1195 = QuestInfo()
QI1196 = QuestInfo()
QI1200 = QuestInfo()
QI1201 = QuestInfo()
QI1202 = QuestInfo()
QI1203 = QuestInfo()
QI1204 = QuestInfo()
QI1205 = QuestInfo()
QI1206 = QuestInfo()
QI1213 = QuestInfo()
QI1214 = QuestInfo()
QI1215 = QuestInfo()
QI1216 = QuestInfo()
QI1217 = QuestInfo()
QI1218 = QuestInfo()
QI1219 = QuestInfo()
QI1220 = QuestInfo()
QI1221 = QuestInfo()
QI1222 = QuestInfo()
QI0 = QuestInfo()
QI1 = QuestInfo()
QI2 = QuestInfo()
QI3 = QuestInfo()
QI4 = QuestInfo()
QI5 = QuestInfo()
QI6 = QuestInfo()
QI7 = QuestInfo()
QI8 = QuestInfo()
QI9 = QuestInfo()
QI10 = QuestInfo()
QI11 = QuestInfo()
QI12 = QuestInfo()
QI13 = QuestInfo()
QI14 = QuestInfo()
QI15 = QuestInfo()
QI16 = QuestInfo()
QI17 = QuestInfo()
QI18 = QuestInfo()
QI19 = QuestInfo()
QI20 = QuestInfo()
QI21 = QuestInfo()
QI22 = QuestInfo()
QI23 = QuestInfo()
QI24 = QuestInfo()
QI25 = QuestInfo()
QI26 = QuestInfo()
QI27 = QuestInfo()
QI28 = QuestInfo()
QI29 = QuestInfo()
QI30 = QuestInfo()
QI31 = QuestInfo()
QI32 = QuestInfo()
QI33 = QuestInfo()
QI34 = QuestInfo()
QI35 = QuestInfo()
QI36 = QuestInfo()
QI37 = QuestInfo()
QI38 = QuestInfo()
QI39 = QuestInfo()
QI40 = QuestInfo()
QI41 = QuestInfo()
QI42 = QuestInfo()
QI43 = QuestInfo()
QI44 = QuestInfo()
QI45 = QuestInfo()
QI46 = QuestInfo()
QI47 = QuestInfo()
QI48 = QuestInfo()
QI49 = QuestInfo()
QI50 = QuestInfo()
QI51 = QuestInfo()
QI52 = QuestInfo()
QI53 = QuestInfo()
QI54 = QuestInfo()
QI55 = QuestInfo()
QI56 = QuestInfo()
QI57 = QuestInfo()
QI58 = QuestInfo()
QI59 = QuestInfo()
QI60 = QuestInfo()
QI61 = QuestInfo()
QI62 = QuestInfo()
QI63 = QuestInfo()
QI64 = QuestInfo()
QI65 = QuestInfo()
QI66 = QuestInfo()
QI67 = QuestInfo()
QI68 = QuestInfo()
QI69 = QuestInfo()
QI70 = QuestInfo()
QI71 = QuestInfo()
QI72 = QuestInfo()
QI73 = QuestInfo()
QI74 = QuestInfo()
QI75 = QuestInfo()
QI76 = QuestInfo()
QI77 = QuestInfo()
QI78 = QuestInfo()
QI79 = QuestInfo()
QI80 = QuestInfo()
QI81 = QuestInfo()
QI82 = QuestInfo()
QI83 = QuestInfo()
QI84 = QuestInfo()
QI85 = QuestInfo()
QI86 = QuestInfo()
QI87 = QuestInfo()
QI88 = QuestInfo()
QI89 = QuestInfo()
QI90 = QuestInfo()
QI91 = QuestInfo()
QI92 = QuestInfo()
QI93 = QuestInfo()
QI94 = QuestInfo()
QI95 = QuestInfo()
QI96 = QuestInfo()
QI97 = QuestInfo()
QI98 = QuestInfo()
QI99 = QuestInfo()
QI100 = QuestInfo()
QI101 = QuestInfo()
QI102 = QuestInfo()
QI103 = QuestInfo()
QI104 = QuestInfo()
QI105 = QuestInfo()
QI106 = QuestInfo()
QI107 = QuestInfo()
QI108 = QuestInfo()
QI109 = QuestInfo()
QI110 = QuestInfo()
QI111 = QuestInfo()
QI112 = QuestInfo()
QI113 = QuestInfo()
QI114 = QuestInfo()
QI115 = QuestInfo()
QI116 = QuestInfo()
QI117 = QuestInfo()
QI118 = QuestInfo()
QI119 = QuestInfo()
QI120 = QuestInfo()
QI121 = QuestInfo()
QI122 = QuestInfo()
QI123 = QuestInfo()
QI124 = QuestInfo()
QI125 = QuestInfo()
QI126 = QuestInfo()
QI127 = QuestInfo()
QI128 = QuestInfo()
QI129 = QuestInfo()
QI130 = QuestInfo()
QI131 = QuestInfo()
QI132 = QuestInfo()
QI133 = QuestInfo()
QI134 = QuestInfo()
QI135 = QuestInfo()
QI136 = QuestInfo()
QI137 = QuestInfo()
QI138 = QuestInfo()
QI139 = QuestInfo()
QI140 = QuestInfo()
QI141 = QuestInfo()
QI142 = QuestInfo()
QI143 = QuestInfo()
QI144 = QuestInfo()
QI145 = QuestInfo()
QI146 = QuestInfo()
QI147 = QuestInfo()
QI148 = QuestInfo()
QI149 = QuestInfo()
QI150 = QuestInfo()
QI151 = QuestInfo()
QI152 = QuestInfo()
QI153 = QuestInfo()
QI154 = QuestInfo()
QI155 = QuestInfo()
QI156 = QuestInfo()
QI157 = QuestInfo()
QI158 = QuestInfo()
QI159 = QuestInfo()
QI160 = QuestInfo()
QI161 = QuestInfo()
QI162 = QuestInfo()
QI163 = QuestInfo()
QI164 = QuestInfo()
QI165 = QuestInfo()
QI166 = QuestInfo()
QI167 = QuestInfo()
QI168 = QuestInfo()
QI169 = QuestInfo()
QI170 = QuestInfo()
QI171 = QuestInfo()
QI172 = QuestInfo()
QI173 = QuestInfo()
QI174 = QuestInfo()
QI175 = QuestInfo()
QI176 = QuestInfo()
QI177 = QuestInfo()
QI178 = QuestInfo()
QI179 = QuestInfo()
QI180 = QuestInfo()
QI181 = QuestInfo()
QI182 = QuestInfo()
QI183 = QuestInfo()
QI184 = QuestInfo()
QI185 = QuestInfo()
QI186 = QuestInfo()
QI187 = QuestInfo()
QI207 = QuestInfo()
QI208 = QuestInfo()
QI209 = QuestInfo()
QI223 = QuestInfo()
QI224 = QuestInfo()
QI225 = QuestInfo()
QI226 = QuestInfo()
QI210 = QuestInfo()
QI211 = QuestInfo()
QI212 = QuestInfo()
QI227 = QuestInfo()
QI228 = QuestInfo()
QI229 = QuestInfo()
QI230 = QuestInfo()
QI188 = QuestInfo()
QI189 = QuestInfo()
QI190 = QuestInfo()
QI191 = QuestInfo()
QI197 = QuestInfo()
QI198 = QuestInfo()
QI199 = QuestInfo()
QI192 = QuestInfo()
QI193 = QuestInfo()
QI194 = QuestInfo()
QI195 = QuestInfo()
QI196 = QuestInfo()
QI200 = QuestInfo()
QI201 = QuestInfo()
QI202 = QuestInfo()
QI203 = QuestInfo()
QI204 = QuestInfo()
QI205 = QuestInfo()
QI206 = QuestInfo()
QI213 = QuestInfo()
QI214 = QuestInfo()
QI215 = QuestInfo()
QI216 = QuestInfo()
QI217 = QuestInfo()
QI218 = QuestInfo()
QI219 = QuestInfo()
QI220 = QuestInfo()
QI221 = QuestInfo()
QI222 = QuestInfo()
QR1000 = QuestReward()
QR1001 = QuestReward()
QR1002 = QuestReward()
QR1003 = QuestReward()
QR1004 = QuestReward()
QR1005 = QuestReward()
QR1006 = QuestReward()
QR1007 = QuestReward()
QR1008 = QuestReward()
QR1009 = QuestReward()
QR1010 = QuestReward()
QR1011 = QuestReward()
QR1012 = QuestReward()
QR1013 = QuestReward()
QR1014 = QuestReward()
QR1015 = QuestReward()
QR1016 = QuestReward()
QR1017 = QuestReward()
QR1018 = QuestReward()
QR1019 = QuestReward()
QR1020 = QuestReward()
QR1021 = QuestReward()
QR1022 = QuestReward()
QR1023 = QuestReward()
QR1024 = QuestReward()
QR1025 = QuestReward()
QR1026 = QuestReward()
QR1027 = QuestReward()
QR1028 = QuestReward()
QR1029 = QuestReward()
QR1030 = QuestReward()
QR1031 = QuestReward()
QR1032 = QuestReward()
QR1033 = QuestReward()
QR1034 = QuestReward()
QR1035 = QuestReward()
QR1036 = QuestReward()
QR1037 = QuestReward()
QR1038 = QuestReward()
QR1039 = QuestReward()
QR1040 = QuestReward()
QR1041 = QuestReward()
QR1042 = QuestReward()
QR1043 = QuestReward()
QR1044 = QuestReward()
QR1045 = QuestReward()
QR1046 = QuestReward()
QR1047 = QuestReward()
QR1048 = QuestReward()
QR1049 = QuestReward()
QR1050 = QuestReward()
QR1051 = QuestReward()
QR1052 = QuestReward()
QR1053 = QuestReward()
QR1054 = QuestReward()
QR1055 = QuestReward()
QR1056 = QuestReward()
QR1057 = QuestReward()
QR1058 = QuestReward()
QR1059 = QuestReward()
QR1060 = QuestReward()
QR1061 = QuestReward()
QR1062 = QuestReward()
QR1063 = QuestReward()
QR1064 = QuestReward()
QR1065 = QuestReward()
QR1066 = QuestReward()
QR1067 = QuestReward()
QR1068 = QuestReward()
QR1069 = QuestReward()
QR1070 = QuestReward()
QR1071 = QuestReward()
QR1072 = QuestReward()
QR1073 = QuestReward()
QR1074 = QuestReward()
QR1075 = QuestReward()
QR1076 = QuestReward()
QR1077 = QuestReward()
QR1078 = QuestReward()
QR1079 = QuestReward()
QR1080 = QuestReward()
QR1081 = QuestReward()
QR1082 = QuestReward()
QR1083 = QuestReward()
QR1084 = QuestReward()
QR1085 = QuestReward()
QR1086 = QuestReward()
QR1087 = QuestReward()
QR1088 = QuestReward()
QR1089 = QuestReward()
QR1090 = QuestReward()
QR1091 = QuestReward()
QR1092 = QuestReward()
QR1093 = QuestReward()
QR1094 = QuestReward()
QR1095 = QuestReward()
QR1096 = QuestReward()
QR1097 = QuestReward()
QR1098 = QuestReward()
QR1099 = QuestReward()
QR1100 = QuestReward()
QR1101 = QuestReward()
QR1102 = QuestReward()
QR1103 = QuestReward()
QR1104 = QuestReward()
QR1105 = QuestReward()
QR1106 = QuestReward()
QR1107 = QuestReward()
QR1108 = QuestReward()
QR1109 = QuestReward()
QR1110 = QuestReward()
QR1111 = QuestReward()
QR1112 = QuestReward()
QR1113 = QuestReward()
QR1114 = QuestReward()
QR1115 = QuestReward()
QR1116 = QuestReward()
QR1117 = QuestReward()
QR1118 = QuestReward()
QR1119 = QuestReward()
QR1120 = QuestReward()
QR1121 = QuestReward()
QR1122 = QuestReward()
QR1123 = QuestReward()
QR1124 = QuestReward()
QR1125 = QuestReward()
QR1126 = QuestReward()
QR1127 = QuestReward()
QR1128 = QuestReward()
QR1129 = QuestReward()
QR1130 = QuestReward()
QR1131 = QuestReward()
QR1132 = QuestReward()
QR1133 = QuestReward()
QR1134 = QuestReward()
QR1135 = QuestReward()
QR1136 = QuestReward()
QR1137 = QuestReward()
QR1138 = QuestReward()
QR1139 = QuestReward()
QR1140 = QuestReward()
QR1141 = QuestReward()
QR1142 = QuestReward()
QR1143 = QuestReward()
QR1144 = QuestReward()
QR1145 = QuestReward()
QR1146 = QuestReward()
QR1147 = QuestReward()
QR1148 = QuestReward()
QR1149 = QuestReward()
QR1150 = QuestReward()
QR1151 = QuestReward()
QR1152 = QuestReward()
QR1153 = QuestReward()
QR1154 = QuestReward()
QR1155 = QuestReward()
QR1156 = QuestReward()
QR1157 = QuestReward()
QR1158 = QuestReward()
QR1159 = QuestReward()
QR1160 = QuestReward()
QR1161 = QuestReward()
QR1162 = QuestReward()
QR1163 = QuestReward()
QR1164 = QuestReward()
QR1165 = QuestReward()
QR1166 = QuestReward()
QR1167 = QuestReward()
QR1168 = QuestReward()
QR1169 = QuestReward()
QR1170 = QuestReward()
QR1171 = QuestReward()
QR1172 = QuestReward()
QR1173 = QuestReward()
QR1174 = QuestReward()
QR1175 = QuestReward()
QR1176 = QuestReward()
QR1177 = QuestReward()
QR1178 = QuestReward()
QR1179 = QuestReward()
QR1180 = QuestReward()
QR1181 = QuestReward()
QR1182 = QuestReward()
QR1183 = QuestReward()
QR1184 = QuestReward()
QR1185 = QuestReward()
QR1186 = QuestReward()
QR1187 = QuestReward()
QR1207 = QuestReward()
QR1208 = QuestReward()
QR1209 = QuestReward()
QR1223 = QuestReward()
QR1224 = QuestReward()
QR1225 = QuestReward()
QR1226 = QuestReward()
QR1210 = QuestReward()
QR1211 = QuestReward()
QR1212 = QuestReward()
QR1227 = QuestReward()
QR1228 = QuestReward()
QR1229 = QuestReward()
QR1230 = QuestReward()
QR1188 = QuestReward()
QR1189 = QuestReward()
QR1190 = QuestReward()
QR1191 = QuestReward()
QR1197 = QuestReward()
QR1198 = QuestReward()
QR1199 = QuestReward()
QR1192 = QuestReward()
QR1193 = QuestReward()
QR1194 = QuestReward()
QR1195 = QuestReward()
QR1196 = QuestReward()
QR1200 = QuestReward()
QR1201 = QuestReward()
QR1202 = QuestReward()
QR1203 = QuestReward()
QR1204 = QuestReward()
QR1205 = QuestReward()
QR1206 = QuestReward()
QR1213 = QuestReward()
QR1214 = QuestReward()
QR1215 = QuestReward()
QR1216 = QuestReward()
QR1217 = QuestReward()
QR1218 = QuestReward()
QR1219 = QuestReward()
QR1220 = QuestReward()
QR1221 = QuestReward()
QR1222 = QuestReward()
QR0 = QuestReward()
QR1 = QuestReward()
QR2 = QuestReward()
QR3 = QuestReward()
QR4 = QuestReward()
QR5 = QuestReward()
QR6 = QuestReward()
QR7 = QuestReward()
QR8 = QuestReward()
QR9 = QuestReward()
QR10 = QuestReward()
QR11 = QuestReward()
QR12 = QuestReward()
QR13 = QuestReward()
QR14 = QuestReward()
QR15 = QuestReward()
QR16 = QuestReward()
QR17 = QuestReward()
QR18 = QuestReward()
QR19 = QuestReward()
QR20 = QuestReward()
QR21 = QuestReward()
QR22 = QuestReward()
QR23 = QuestReward()
QR24 = QuestReward()
QR25 = QuestReward()
QR26 = QuestReward()
QR27 = QuestReward()
QR28 = QuestReward()
QR29 = QuestReward()
QR30 = QuestReward()
QR31 = QuestReward()
QR32 = QuestReward()
QR33 = QuestReward()
QR34 = QuestReward()
QR35 = QuestReward()
QR36 = QuestReward()
QR37 = QuestReward()
QR38 = QuestReward()
QR39 = QuestReward()
QR40 = QuestReward()
QR41 = QuestReward()
QR42 = QuestReward()
QR43 = QuestReward()
QR44 = QuestReward()
QR45 = QuestReward()
QR46 = QuestReward()
QR47 = QuestReward()
QR48 = QuestReward()
QR49 = QuestReward()
QR50 = QuestReward()
QR51 = QuestReward()
QR52 = QuestReward()
QR53 = QuestReward()
QR54 = QuestReward()
QR55 = QuestReward()
QR56 = QuestReward()
QR57 = QuestReward()
QR58 = QuestReward()
QR59 = QuestReward()
QR60 = QuestReward()
QR61 = QuestReward()
QR62 = QuestReward()
QR63 = QuestReward()
QR64 = QuestReward()
QR65 = QuestReward()
QR66 = QuestReward()
QR67 = QuestReward()
QR68 = QuestReward()
QR69 = QuestReward()
QR70 = QuestReward()
QR71 = QuestReward()
QR72 = QuestReward()
QR73 = QuestReward()
QR74 = QuestReward()
QR75 = QuestReward()
QR76 = QuestReward()
QR77 = QuestReward()
QR78 = QuestReward()
QR79 = QuestReward()
QR80 = QuestReward()
QR81 = QuestReward()
QR82 = QuestReward()
QR83 = QuestReward()
QR84 = QuestReward()
QR85 = QuestReward()
QR86 = QuestReward()
QR87 = QuestReward()
QR88 = QuestReward()
QR89 = QuestReward()
QR90 = QuestReward()
QR91 = QuestReward()
QR92 = QuestReward()
QR93 = QuestReward()
QR94 = QuestReward()
QR95 = QuestReward()
QR96 = QuestReward()
QR97 = QuestReward()
QR98 = QuestReward()
QR99 = QuestReward()
QR100 = QuestReward()
QR101 = QuestReward()
QR102 = QuestReward()
QR103 = QuestReward()
QR104 = QuestReward()
QR105 = QuestReward()
QR106 = QuestReward()
QR107 = QuestReward()
QR108 = QuestReward()
QR109 = QuestReward()
QR110 = QuestReward()
QR111 = QuestReward()
QR112 = QuestReward()
QR113 = QuestReward()
QR114 = QuestReward()
QR115 = QuestReward()
QR116 = QuestReward()
QR117 = QuestReward()
QR118 = QuestReward()
QR119 = QuestReward()
QR120 = QuestReward()
QR121 = QuestReward()
QR122 = QuestReward()
QR123 = QuestReward()
QR124 = QuestReward()
QR125 = QuestReward()
QR126 = QuestReward()
QR127 = QuestReward()
QR128 = QuestReward()
QR129 = QuestReward()
QR130 = QuestReward()
QR131 = QuestReward()
QR132 = QuestReward()
QR133 = QuestReward()
QR134 = QuestReward()
QR135 = QuestReward()
QR136 = QuestReward()
QR137 = QuestReward()
QR138 = QuestReward()
QR139 = QuestReward()
QR140 = QuestReward()
QR141 = QuestReward()
QR142 = QuestReward()
QR143 = QuestReward()
QR144 = QuestReward()
QR145 = QuestReward()
QR146 = QuestReward()
QR147 = QuestReward()
QR148 = QuestReward()
QR149 = QuestReward()
QR150 = QuestReward()
QR151 = QuestReward()
QR152 = QuestReward()
QR153 = QuestReward()
QR154 = QuestReward()
QR155 = QuestReward()
QR156 = QuestReward()
QR157 = QuestReward()
QR158 = QuestReward()
QR159 = QuestReward()
QR160 = QuestReward()
QR161 = QuestReward()
QR162 = QuestReward()
QR163 = QuestReward()
QR164 = QuestReward()
QR165 = QuestReward()
QR166 = QuestReward()
QR167 = QuestReward()
QR168 = QuestReward()
QR169 = QuestReward()
QR170 = QuestReward()
QR171 = QuestReward()
QR172 = QuestReward()
QR173 = QuestReward()
QR174 = QuestReward()
QR175 = QuestReward()
QR176 = QuestReward()
QR177 = QuestReward()
QR178 = QuestReward()
QR179 = QuestReward()
QR180 = QuestReward()
QR181 = QuestReward()
QR182 = QuestReward()
QR183 = QuestReward()
QR184 = QuestReward()
QR185 = QuestReward()
QR186 = QuestReward()
QR187 = QuestReward()
QR207 = QuestReward()
QR208 = QuestReward()
QR209 = QuestReward()
QR223 = QuestReward()
QR224 = QuestReward()
QR225 = QuestReward()
QR226 = QuestReward()
QR210 = QuestReward()
QR211 = QuestReward()
QR212 = QuestReward()
QR227 = QuestReward()
QR228 = QuestReward()
QR229 = QuestReward()
QR230 = QuestReward()
QR188 = QuestReward()
QR189 = QuestReward()
QR190 = QuestReward()
QR191 = QuestReward()
QR197 = QuestReward()
QR198 = QuestReward()
QR199 = QuestReward()
QR192 = QuestReward()
QR193 = QuestReward()
QR194 = QuestReward()
QR195 = QuestReward()
QR196 = QuestReward()
QR200 = QuestReward()
QR201 = QuestReward()
QR202 = QuestReward()
QR203 = QuestReward()
QR204 = QuestReward()
QR205 = QuestReward()
QR206 = QuestReward()
QR213 = QuestReward()
QR214 = QuestReward()
QR215 = QuestReward()
QR216 = QuestReward()
QR217 = QuestReward()
QR218 = QuestReward()
QR219 = QuestReward()
QR220 = QuestReward()
QR221 = QuestReward()
QR222 = QuestReward()
# 1000
QI1000.QuestID =1000
QI1000.QuestSort =0
QI1000.NextQuestId =1001
QI1000.MinLevel =1
QI1000.RequiredFaction =1
QI1000.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1000.Color =0
QI1000.Repeat =1
QI1000.RewardItem[0].Base =2900
QI1000.RewardItem[0].Append =[50,-1,-1,-1,-1]
QI1000.RewardItem[0].BaseLv =1
QI1000.RewardItem[0].AppendLv =1
QI1000.RewardItem[0].Overlap =1
QI1000.RewardItem[0].Binding =1
QI1000.RewardItem[1].Base =2900
QI1000.RewardItem[1].Append =[130,-1,-1,-1,-1]
QI1000.RewardItem[1].BaseLv =1
QI1000.RewardItem[1].AppendLv =1
QI1000.RewardItem[1].Overlap =1
QI1000.RewardItem[1].Binding =1
QI1000.RewardItem[2].Base =2900
QI1000.RewardItem[2].Append =[150,-1,-1,-1,-1]
QI1000.RewardItem[2].BaseLv =1
QI1000.RewardItem[2].AppendLv =1
QI1000.RewardItem[2].Overlap =1
QI1000.RewardItem[2].Binding =1
QR1000.QuestID =1000
QR1000.EXP =100

# 1001
QI1001.QuestID =1001
QI1001.QuestSort =0
QI1001.PrevQuestId =1000
QI1001.NextQuestId =1002
QI1001.MinLevel =1
QI1001.RequiredFaction =1
QI1001.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1001.Color =0
QI1001.Repeat =1
QI1001.RewardItem[0].Base =4000
QI1001.RewardItem[0].Overlap =10
QI1001.RewardItem[0].Binding =0
QR1001.QuestID =1001
QR1001.EXP =100

# 1002
QI1002.QuestID =1002
QI1002.QuestSort =0
QI1002.PrevQuestId =1001
QI1002.NextQuestId =1003
QI1002.MinLevel =1
QI1002.RequiredFaction =1
QI1002.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1002.Color =0
QI1002.Repeat =1
QI1002.RewardItem[0].Base =4030
QI1002.RewardItem[0].Overlap =10
QI1002.RewardItem[0].Binding =0
QR1002.QuestID =1002
QR1002.EXP =150

# 1003
QI1003.QuestID =1003
QI1003.QuestSort =0
QI1003.PrevQuestId =1002
QI1003.NextQuestId =1004
QI1003.MinLevel =1
QI1003.RequiredFaction =1
QI1003.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1003.Color =0
QI1003.Repeat =1
QI1003.RewardItem[0].Base =2800
QI1003.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI1003.RewardItem[0].BaseLv =1
QI1003.RewardItem[0].AppendLv =1
QI1003.RewardItem[0].Overlap =1
QI1003.RewardItem[0].Binding =1
QI1003.RewardItem[1].Base =2800
QI1003.RewardItem[1].Append =[20,-1,-1,-1,-1]
QI1003.RewardItem[1].BaseLv =1
QI1003.RewardItem[1].AppendLv =1
QI1003.RewardItem[1].Overlap =1
QI1003.RewardItem[1].Binding =1
QR1003.QuestID =1003
QR1003.EXP =150

# 1004
QI1004.QuestID =1004
QI1004.QuestSort =0
QI1004.PrevQuestId =1003
QI1004.NextQuestId =1005
QI1004.MinLevel =1
QI1004.RequiredFaction =1
QI1004.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1004.Color =0
QI1004.Repeat =1
QI1004.RewardMoney =2000
QI1004.RewardItem[0].Base =1000
QI1004.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI1004.RewardItem[0].BaseLv =1
QI1004.RewardItem[0].AppendLv =1
QI1004.RewardItem[0].Overlap =1
QI1004.RewardItem[0].Binding =1
QI1004.RewardItem[1].Base =1400
QI1004.RewardItem[1].Append =[0,-1,-1,-1,-1]
QI1004.RewardItem[1].BaseLv =1
QI1004.RewardItem[1].AppendLv =1
QI1004.RewardItem[1].Overlap =1
QI1004.RewardItem[1].Binding =1
QI1004.RewardItem[2].Base =1700
QI1004.RewardItem[2].Append =[20,-1,-1,-1,-1]
QI1004.RewardItem[2].BaseLv =1
QI1004.RewardItem[2].AppendLv =1
QI1004.RewardItem[2].Overlap =1
QI1004.RewardItem[2].Binding =1
QI1004.RewardItem[3].Base =1800
QI1004.RewardItem[3].Append =[20,-1,-1,-1,-1]
QI1004.RewardItem[3].BaseLv =1
QI1004.RewardItem[3].AppendLv =1
QI1004.RewardItem[3].Overlap =1
QI1004.RewardItem[3].Binding =1
QR1004.QuestID =1004
QR1004.EXP =0
QR1004.SkillPoint =1

# 1005
QI1005.QuestID =1005
QI1005.QuestSort =0
QI1005.PrevQuestId =1004
QI1005.NextQuestId =1006
QI1005.MinLevel =1
QI1005.RequiredFaction =1
QI1005.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1005.Color =0
QI1005.Creature =[1010,-1,-1,-1]
QI1005.CreatureCount =[20,-1,-1,-1]
QI1005.Repeat =1
QI1005.RewardItem[0].Base =2100
QI1005.RewardItem[0].Append =[100,-1,-1,-1,-1]
QI1005.RewardItem[0].BaseLv =1
QI1005.RewardItem[0].AppendLv =1
QI1005.RewardItem[0].Overlap =1
QI1005.RewardItem[0].Binding =1
QI1005.RewardItem[1].Base =2200
QI1005.RewardItem[1].Append =[100,-1,-1,-1,-1]
QI1005.RewardItem[1].BaseLv =1
QI1005.RewardItem[1].AppendLv =1
QI1005.RewardItem[1].Overlap =1
QI1005.RewardItem[1].Binding =1
QR1005.QuestID =1005
QR1005.EXP =500
QR1005.SkillPoint =1

# 1006
QI1006.QuestID =1006
QI1006.QuestSort =0
QI1006.PrevQuestId =1005
QI1006.NextQuestId =1007
QI1006.MinLevel =1
QI1006.RequiredFaction =1
QI1006.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1006.Color =0
QI1006.Repeat =1
QR1006.QuestID =1006
QR1006.EXP =150

# 1007
QI1007.QuestID =1007
QI1007.QuestSort =0
QI1007.PrevQuestId =1006
QI1007.NextQuestId =1008
QI1007.MinLevel =1
QI1007.RequiredFaction =1
QI1007.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1007.Color =0
QI1007.Repeat =1
QR1007.QuestID =1007
QR1007.EXP =150

# 1008
QI1008.QuestID =1008
QI1008.QuestSort =0
QI1008.PrevQuestId =1007
QI1008.NextQuestId =1009
QI1008.MinLevel =1
QI1008.RequiredFaction =1
QI1008.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1008.Color =0
QI1008.Creature =[1011,-1,-1,-1]
QI1008.CreatureCount =[20,-1,-1,-1]
QI1008.Repeat =1
QI1008.RewardItem[0].Base =3000
QI1008.RewardItem[0].Append =[100,-1,-1,-1,-1]
QI1008.RewardItem[0].BaseLv =2
QI1008.RewardItem[0].AppendLv =2
QI1008.RewardItem[0].Overlap =1
QI1008.RewardItem[0].Binding =1
QR1008.QuestID =1008
QR1008.EXP =700
QR1008.SkillPoint =1

# 1009
QI1009.QuestID =1009
QI1009.QuestSort =0
QI1009.PrevQuestId =1008
QI1009.NextQuestId =1010
QI1009.MinLevel =1
QI1009.RequiredFaction =1
QI1009.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1009.Color =0
QI1009.Creature =[1013,-1,-1,-1]
QI1009.CreatureCount =[20,-1,-1,-1]
QI1009.Repeat =1
QR1009.QuestID =1009
QR1009.EXP =800
QR1009.SkillPoint =1

# 1010
QI1010.QuestID =1010
QI1010.QuestSort =0
QI1010.PrevQuestId =1009
QI1010.NextQuestId =1011
QI1010.MinLevel =1
QI1010.RequiredFaction =1
QI1010.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1010.Color =0
QI1010.Repeat =1
QI1010.RewardItem[0].Base =2300
QI1010.RewardItem[0].Append =[80,130,-1,-1,-1]
QI1010.RewardItem[0].BaseLv =1
QI1010.RewardItem[0].AppendLv =1
QI1010.RewardItem[0].Overlap =1
QI1010.RewardItem[0].Binding =1
QI1010.RewardItem[1].Base =2400
QI1010.RewardItem[1].Append =[90,130,-1,-1,-1]
QI1010.RewardItem[1].BaseLv =1
QI1010.RewardItem[1].AppendLv =1
QI1010.RewardItem[1].Overlap =1
QI1010.RewardItem[1].Binding =1
QR1010.QuestID =1010
QR1010.EXP =200

# 1011
QI1011.QuestID =1011
QI1011.QuestSort =0
QI1011.PrevQuestId =1010
QI1011.NextQuestId =1012
QI1011.MinLevel =1
QI1011.RequiredFaction =1
QI1011.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1011.Color =0
QI1011.Repeat =1
QI1011.RewardItem[0].Base =2600
QI1011.RewardItem[0].Append =[10,-1,-1,-1,-1]
QI1011.RewardItem[0].BaseLv =1
QI1011.RewardItem[0].AppendLv =1
QI1011.RewardItem[0].Overlap =1
QI1011.RewardItem[0].Binding =1
QI1011.RewardItem[1].Base =2600
QI1011.RewardItem[1].Append =[40,-1,-1,-1,-1]
QI1011.RewardItem[1].BaseLv =1
QI1011.RewardItem[1].AppendLv =1
QI1011.RewardItem[1].Overlap =1
QI1011.RewardItem[1].Binding =1
QI1011.RewardItem[2].Base =2600
QI1011.RewardItem[2].Append =[150,-1,-1,-1,-1]
QI1011.RewardItem[2].BaseLv =1
QI1011.RewardItem[2].AppendLv =1
QI1011.RewardItem[2].Overlap =1
QI1011.RewardItem[2].Binding =1
QR1011.QuestID =1011
QR1011.EXP =200

# 1012
QI1012.QuestID =1012
QI1012.QuestSort =0
QI1012.PrevQuestId =1011
QI1012.NextQuestId =1013
QI1012.MinLevel =10
QI1012.RequiredFaction =1
QI1012.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1012.Color =0
QI1012.Creature =[1012,-1,-1,-1]
QI1012.CreatureCount =[20,-1,-1,-1]
QI1012.Repeat =1
QI1012.RewardItem[0].Base =2700
QI1012.RewardItem[0].Append =[10,-1,-1,-1,-1]
QI1012.RewardItem[0].BaseLv =1
QI1012.RewardItem[0].AppendLv =1
QI1012.RewardItem[0].Overlap =1
QI1012.RewardItem[0].Binding =1
QI1012.RewardItem[1].Base =2700
QI1012.RewardItem[1].Append =[50,-1,-1,-1,-1]
QI1012.RewardItem[1].BaseLv =1
QI1012.RewardItem[1].AppendLv =1
QI1012.RewardItem[1].Overlap =1
QI1012.RewardItem[1].Binding =1
QI1012.RewardItem[2].Base =2700
QI1012.RewardItem[2].Append =[120,-1,-1,-1,-1]
QI1012.RewardItem[2].BaseLv =1
QI1012.RewardItem[2].AppendLv =1
QI1012.RewardItem[2].Overlap =1
QI1012.RewardItem[2].Binding =1
QI1012.RequiredLevel =10
QR1012.QuestID =1012
QR1012.EXP =1000
QR1012.SkillPoint =1

# 1013
QI1013.QuestID =1013
QI1013.QuestSort =0
QI1013.PrevQuestId =1012
QI1013.NextQuestId =1014
QI1013.MinLevel =11
QI1013.RequiredFaction =1
QI1013.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1013.Color =0
QI1013.Item =[101,-1,-1,-1]
QI1013.ItemCount =[10,-1,-1,-1]
QI1013.ItemProbability =[60,-1,-1,-1]
QI1013.Repeat =1
QR1013.QuestID =1013
QR1013.EXP =1200
QR1013.SkillPoint =2

# 1014
QI1014.QuestID =1014
QI1014.QuestSort =0
QI1014.PrevQuestId =1013
QI1014.NextQuestId =1015
QI1014.MinLevel =12
QI1014.RequiredFaction =1
QI1014.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1014.Color =0
QI1014.Repeat =1
QI1014.RewardMoney =3000
QI1014.RewardItem[0].Base =4220
QI1014.RewardItem[0].Overlap =5
QI1014.RewardItem[0].Binding =1
QR1014.QuestID =1014
QR1014.EXP =200

# 1015
QI1015.QuestID =1015
QI1015.QuestSort =0
QI1015.PrevQuestId =1014
QI1015.NextQuestId =1016
QI1015.MinLevel =12
QI1015.RequiredFaction =1
QI1015.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1015.Color =0
QI1015.Repeat =1
QI1015.RequiredLevel =12
QR1015.QuestID =1015
QR1015.EXP =500
QR1015.SkillPoint =1

# 1016
QI1016.QuestID =1016
QI1016.QuestSort =0
QI1016.PrevQuestId =1015
QI1016.NextQuestId =1017
QI1016.MinLevel =13
QI1016.RequiredFaction =1
QI1016.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1016.Color =0
QI1016.Creature =[1016,-1,-1,-1]
QI1016.CreatureCount =[20,-1,-1,-1]
QI1016.Repeat =1
QI1016.RewardItem[0].Base =3100
QI1016.RewardItem[0].Append =[50,-1,-1,-1,-1]
QI1016.RewardItem[0].BaseLv =2
QI1016.RewardItem[0].AppendLv =1
QI1016.RewardItem[0].Overlap =1
QI1016.RewardItem[0].Binding =1
QI1016.RewardItem[1].Base =3100
QI1016.RewardItem[1].Append =[70,-1,-1,-1,-1]
QI1016.RewardItem[1].BaseLv =2
QI1016.RewardItem[1].AppendLv =1
QI1016.RewardItem[1].Overlap =1
QI1016.RewardItem[1].Binding =1
QI1016.RewardItem[2].Base =3100
QI1016.RewardItem[2].Append =[120,-1,-1,-1,-1]
QI1016.RewardItem[2].BaseLv =2
QI1016.RewardItem[2].AppendLv =1
QI1016.RewardItem[2].Overlap =1
QI1016.RewardItem[2].Binding =1
QR1016.QuestID =1016
QR1016.EXP =1400
QR1016.SkillPoint =2

# 1017
QI1017.QuestID =1017
QI1017.QuestSort =0
QI1017.PrevQuestId =1016
QI1017.NextQuestId =1018
QI1017.MinLevel =13
QI1017.RequiredFaction =1
QI1017.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1017.Color =0
QI1017.Repeat =1
QR1017.QuestID =1017
QR1017.EXP =400

# 1018
QI1018.QuestID =1018
QI1018.QuestSort =0
QI1018.PrevQuestId =1017
QI1018.NextQuestId =1019
QI1018.MinLevel =14
QI1018.RequiredFaction =1
QI1018.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1018.Color =0
QI1018.Repeat =1
QR1018.QuestID =1018
QR1018.EXP =400

# 1019
QI1019.QuestID =1019
QI1019.QuestSort =0
QI1019.PrevQuestId =1018
QI1019.NextQuestId =1020
QI1019.MinLevel =15
QI1019.RequiredFaction =1
QI1019.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1019.Color =0
QI1019.Repeat =1
QI1019.RequiredLevel =16
QR1019.QuestID =1019
QR1019.EXP =400

# 1020
QI1020.QuestID =1020
QI1020.QuestSort =0
QI1020.PrevQuestId =1019
QI1020.NextQuestId =1021
QI1020.MinLevel =16
QI1020.RequiredFaction =1
QI1020.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1020.Color =0
QI1020.Creature =[1018,-1,-1,-1]
QI1020.CreatureCount =[20,-1,-1,-1]
QI1020.Repeat =1
QI1020.RewardItem[0].Base =1001
QI1020.RewardItem[0].Append =[40,-1,-1,-1,-1]
QI1020.RewardItem[0].BaseLv =2
QI1020.RewardItem[0].AppendLv =1
QI1020.RewardItem[0].Overlap =1
QI1020.RewardItem[0].Binding =1
QI1020.RewardItem[1].Base =1401
QI1020.RewardItem[1].Append =[60,-1,-1,-1,-1]
QI1020.RewardItem[1].BaseLv =2
QI1020.RewardItem[1].AppendLv =1
QI1020.RewardItem[1].Overlap =1
QI1020.RewardItem[1].Binding =1
QI1020.RewardItem[2].Base =1701
QI1020.RewardItem[2].Append =[40,-1,-1,-1,-1]
QI1020.RewardItem[2].BaseLv =2
QI1020.RewardItem[2].AppendLv =1
QI1020.RewardItem[2].Overlap =1
QI1020.RewardItem[2].Binding =1
QI1020.RewardItem[3].Base =1801
QI1020.RewardItem[3].Append =[60,-1,-1,-1,-1]
QI1020.RewardItem[3].BaseLv =2
QI1020.RewardItem[3].AppendLv =1
QI1020.RewardItem[3].Overlap =1
QI1020.RewardItem[3].Binding =1
QR1020.QuestID =1020
QR1020.EXP =1600
QR1020.SkillPoint =2

# 1021
QI1021.QuestID =1021
QI1021.QuestSort =0
QI1021.PrevQuestId =1020
QI1021.NextQuestId =1022
QI1021.MinLevel =17
QI1021.RequiredFaction =1
QI1021.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1021.Color =0
QI1021.Repeat =1
QR1021.QuestID =1021
QR1021.EXP =400

# 1022
QI1022.QuestID =1022
QI1022.QuestSort =0
QI1022.PrevQuestId =1021
QI1022.NextQuestId =1023
QI1022.MinLevel =18
QI1022.RequiredFaction =1
QI1022.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1022.Color =0
QI1022.Repeat =1
QR1022.QuestID =1022
QR1022.EXP =1000
QR1022.SkillPoint =1

# 1023
QI1023.QuestID =1023
QI1023.QuestSort =0
QI1023.PrevQuestId =1022
QI1023.NextQuestId =1024
QI1023.MinLevel =18
QI1023.RequiredFaction =1
QI1023.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1023.Color =0
QI1023.Repeat =1
QR1023.QuestID =1023
QR1023.EXP =500

# 1024
QI1024.QuestID =1024
QI1024.QuestSort =0
QI1024.PrevQuestId =1023
QI1024.NextQuestId =1025
QI1024.MinLevel =19
QI1024.RequiredFaction =1
QI1024.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1024.Color =0
QI1024.Repeat =1
QI1024.RequiredLevel =20
QR1024.QuestID =1024
QR1024.EXP =500
QR1024.SkillPoint =1

# 1025
QI1025.QuestID =1025
QI1025.QuestSort =0
QI1025.PrevQuestId =1024
QI1025.NextQuestId =1026
QI1025.MinLevel =20
QI1025.RequiredFaction =1
QI1025.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1025.Color =0
QI1025.Item =[102,-1,-1,-1]
QI1025.ItemCount =[8,-1,-1,-1]
QI1025.ItemProbability =[40,-1,-1,-1]
QI1025.Repeat =1
QI1025.RewardMoney =4000
QI1025.RewardItem[0].Base =4230
QI1025.RewardItem[0].Overlap =1
QI1025.RewardItem[0].Binding =1
QR1025.QuestID =1025
QR1025.EXP =2000
QR1025.SkillPoint =2

# 1026
QI1026.QuestID =1026
QI1026.QuestSort =0
QI1026.PrevQuestId =1025
QI1026.NextQuestId =1027
QI1026.MinLevel =20
QI1026.RequiredFaction =1
QI1026.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1026.Color =0
QI1026.Repeat =1
QR1026.QuestID =1026
QR1026.EXP =500

# 1027
QI1027.QuestID =1027
QI1027.QuestSort =0
QI1027.PrevQuestId =1026
QI1027.NextQuestId =1028
QI1027.MinLevel =21
QI1027.RequiredFaction =1
QI1027.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1027.Color =0
QI1027.Repeat =1
QI1027.RewardItem[0].Base =1002
QI1027.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI1027.RewardItem[0].BaseLv =2
QI1027.RewardItem[0].AppendLv =2
QI1027.RewardItem[0].Overlap =1
QI1027.RewardItem[0].Binding =1
QI1027.RewardItem[1].Base =1402
QI1027.RewardItem[1].Append =[0,-1,-1,-1,-1]
QI1027.RewardItem[1].BaseLv =2
QI1027.RewardItem[1].AppendLv =2
QI1027.RewardItem[1].Overlap =1
QI1027.RewardItem[1].Binding =1
QI1027.RewardItem[2].Base =1702
QI1027.RewardItem[2].Append =[20,-1,-1,-1,-1]
QI1027.RewardItem[2].BaseLv =2
QI1027.RewardItem[2].AppendLv =2
QI1027.RewardItem[2].Overlap =1
QI1027.RewardItem[2].Binding =1
QI1027.RewardItem[3].Base =1802
QI1027.RewardItem[3].Append =[20,-1,-1,-1,-1]
QI1027.RewardItem[3].BaseLv =2
QI1027.RewardItem[3].AppendLv =2
QI1027.RewardItem[3].Overlap =1
QI1027.RewardItem[3].Binding =1
QR1027.QuestID =1027
QR1027.EXP =800

# 1028
QI1028.QuestID =1028
QI1028.QuestSort =0
QI1028.PrevQuestId =1027
QI1028.NextQuestId =1029
QI1028.MinLevel =22
QI1028.RequiredFaction =1
QI1028.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1028.Color =0
QI1028.Repeat =1
QR1028.QuestID =1028
QR1028.EXP =500

# 1029
QI1029.QuestID =1029
QI1029.QuestSort =0
QI1029.PrevQuestId =1028
QI1029.NextQuestId =1030
QI1029.MinLevel =23
QI1029.RequiredFaction =1
QI1029.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1029.Color =0
QI1029.Repeat =1
QR1029.QuestID =1029
QR1029.EXP =500

# 1030
QI1030.QuestID =1030
QI1030.QuestSort =0
QI1030.PrevQuestId =1029
QI1030.NextQuestId =1031
QI1030.MinLevel =23
QI1030.RequiredFaction =1
QI1030.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1030.Color =0
QI1030.Repeat =1
QR1030.QuestID =1030
QR1030.EXP =500

# 1031
QI1031.QuestID =1031
QI1031.QuestSort =0
QI1031.PrevQuestId =1030
QI1031.NextQuestId =1032
QI1031.MinLevel =24
QI1031.RequiredFaction =1
QI1031.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1031.Color =0
QI1031.Repeat =1
QI1031.RewardItem[0].Base =4001
QI1031.RewardItem[0].Overlap =10
QI1031.RewardItem[0].Binding =0
QR1031.QuestID =1031
QR1031.EXP =800

# 1032
QI1032.QuestID =1032
QI1032.QuestSort =0
QI1032.PrevQuestId =1031
QI1032.NextQuestId =1033
QI1032.MinLevel =24
QI1032.RequiredFaction =1
QI1032.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1032.Color =0
QI1032.Item =[103,-1,-1,-1]
QI1032.ItemCount =[3,-1,-1,-1]
QI1032.ItemProbability =[15,-1,-1,-1]
QI1032.Repeat =1
QI1032.RewardMoney =5000
QR1032.QuestID =1032
QR1032.EXP =2500
QR1032.SkillPoint =1

# 1033
QI1033.QuestID =1033
QI1033.QuestSort =0
QI1033.PrevQuestId =1032
QI1033.NextQuestId =1034
QI1033.MinLevel =24
QI1033.RequiredFaction =1
QI1033.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1033.Color =0
QI1033.Repeat =1
QI1033.RewardItem[0].Base =4031
QI1033.RewardItem[0].Overlap =10
QI1033.RewardItem[0].Binding =0
QR1033.QuestID =1033
QR1033.EXP =600

# 1034
QI1034.QuestID =1034
QI1034.QuestSort =0
QI1034.PrevQuestId =1033
QI1034.NextQuestId =1035
QI1034.MinLevel =25
QI1034.RequiredFaction =1
QI1034.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1034.Color =0
QI1034.Repeat =1
QR1034.QuestID =1034
QR1034.EXP =600

# 1035
QI1035.QuestID =1035
QI1035.QuestSort =0
QI1035.PrevQuestId =1034
QI1035.NextQuestId =1036
QI1035.MinLevel =25
QI1035.RequiredFaction =1
QI1035.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1035.Color =0
QI1035.Repeat =1
QR1035.QuestID =1035
QR1035.EXP =600

# 1036
QI1036.QuestID =1036
QI1036.QuestSort =0
QI1036.PrevQuestId =1035
QI1036.NextQuestId =1037
QI1036.MinLevel =25
QI1036.RequiredFaction =1
QI1036.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1036.Color =0
QI1036.Repeat =1
QR1036.QuestID =1036
QR1036.EXP =600

# 1037
QI1037.QuestID =1037
QI1037.QuestSort =0
QI1037.PrevQuestId =1036
QI1037.NextQuestId =1038
QI1037.MinLevel =26
QI1037.RequiredFaction =1
QI1037.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1037.Color =0
QI1037.Repeat =1
QI1037.RewardItem[0].Base =4220
QI1037.RewardItem[0].Overlap =2
QI1037.RewardItem[0].Binding =1
QR1037.QuestID =1037
QR1037.EXP =600

# 1038
QI1038.QuestID =1038
QI1038.QuestSort =0
QI1038.PrevQuestId =1037
QI1038.NextQuestId =1039
QI1038.MinLevel =26
QI1038.RequiredFaction =1
QI1038.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1038.Color =0
QI1038.Repeat =1
QR1038.QuestID =1038
QR1038.EXP =700

# 1039
QI1039.QuestID =1039
QI1039.QuestSort =0
QI1039.PrevQuestId =1038
QI1039.NextQuestId =1040
QI1039.MinLevel =27
QI1039.RequiredFaction =1
QI1039.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1039.Color =0
QI1039.Repeat =1
QR1039.QuestID =1039
QR1039.EXP =800

# 1040
QI1040.QuestID =1040
QI1040.QuestSort =0
QI1040.PrevQuestId =1039
QI1040.NextQuestId =1041
QI1040.MinLevel =27
QI1040.RequiredFaction =1
QI1040.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1040.Color =0
QI1040.Repeat =1
QI1040.RequiredLevel =28
QR1040.QuestID =1040
QR1040.EXP =900

# 1041
QI1041.QuestID =1041
QI1041.QuestSort =0
QI1041.PrevQuestId =1040
QI1041.NextQuestId =1042
QI1041.MinLevel =28
QI1041.RequiredFaction =1
QI1041.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1041.Color =0
QI1041.Item =[104,-1,-1,-1]
QI1041.ItemCount =[1,-1,-1,-1]
QI1041.ItemProbability =[8,-1,-1,-1]
QI1041.Repeat =1
QI1041.RewardMoney =2000
QI1041.RewardItem[0].Base =4210
QI1041.RewardItem[0].Overlap =2
QI1041.RewardItem[0].Binding =1
QR1041.QuestID =1041
QR1041.EXP =2500
QR1041.SkillPoint =2

# 1042
QI1042.QuestID =1042
QI1042.QuestSort =0
QI1042.PrevQuestId =1041
QI1042.NextQuestId =1043
QI1042.MinLevel =28
QI1042.RequiredFaction =1
QI1042.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1042.Color =0
QI1042.Repeat =1
QR1042.QuestID =1042
QR1042.EXP =700

# 1043
QI1043.QuestID =1043
QI1043.QuestSort =0
QI1043.PrevQuestId =1042
QI1043.NextQuestId =1044
QI1043.MinLevel =28
QI1043.RequiredFaction =1
QI1043.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1043.Color =0
QI1043.Repeat =1
QR1043.QuestID =1043
QR1043.EXP =700

# 1044
QI1044.QuestID =1044
QI1044.QuestSort =0
QI1044.PrevQuestId =1043
QI1044.NextQuestId =1045
QI1044.MinLevel =29
QI1044.RequiredFaction =1
QI1044.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1044.Color =0
QI1044.Repeat =1
QI1044.RewardItem[0].Base =2802
QI1044.RewardItem[0].Append =[0,40,-1,-1,-1]
QI1044.RewardItem[0].BaseLv =2
QI1044.RewardItem[0].AppendLv =1
QI1044.RewardItem[0].Overlap =1
QI1044.RewardItem[0].Binding =1
QI1044.RewardItem[1].Base =2802
QI1044.RewardItem[1].Append =[40,60,-1,-1,-1]
QI1044.RewardItem[1].BaseLv =2
QI1044.RewardItem[1].AppendLv =1
QI1044.RewardItem[1].Overlap =1
QI1044.RewardItem[1].Binding =1
QI1044.RewardItem[2].Base =2802
QI1044.RewardItem[2].Append =[0,110,-1,-1,-1]
QI1044.RewardItem[2].BaseLv =2
QI1044.RewardItem[2].AppendLv =1
QI1044.RewardItem[2].Overlap =1
QI1044.RewardItem[2].Binding =1
QR1044.QuestID =1044
QR1044.EXP =1000

# 1045
QI1045.QuestID =1045
QI1045.QuestSort =0
QI1045.PrevQuestId =1044
QI1045.NextQuestId =1046
QI1045.MinLevel =29
QI1045.RequiredFaction =1
QI1045.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1045.Color =0
QI1045.Repeat =1
QR1045.QuestID =1045
QR1045.EXP =1500
QR1045.SkillPoint =1

# 1046
QI1046.QuestID =1046
QI1046.QuestSort =0
QI1046.PrevQuestId =1045
QI1046.NextQuestId =1047
QI1046.MinLevel =29
QI1046.RequiredFaction =1
QI1046.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1046.Color =0
QI1046.Repeat =1
QR1046.QuestID =1046
QR1046.EXP =700

# 1047
QI1047.QuestID =1047
QI1047.QuestSort =0
QI1047.PrevQuestId =1046
QI1047.NextQuestId =1048
QI1047.MinLevel =30
QI1047.RequiredFaction =1
QI1047.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1047.Color =0
QI1047.Repeat =1
QI1047.RequiredLevel =30
QR1047.QuestID =1047
QR1047.EXP =1000

# 1048
QI1048.QuestID =1048
QI1048.QuestSort =0
QI1048.PrevQuestId =1047
QI1048.NextQuestId =1049
QI1048.MinLevel =30
QI1048.RequiredFaction =1
QI1048.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1048.Color =0
QI1048.Creature =[1030,-1,-1,-1]
QI1048.CreatureCount =[30,-1,-1,-1]
QI1048.Repeat =1
QR1048.QuestID =1048
QR1048.EXP =3000
QR1048.SkillPoint =2

# 1049
QI1049.QuestID =1049
QI1049.QuestSort =0
QI1049.PrevQuestId =1048
QI1049.NextQuestId =1050
QI1049.MinLevel =31
QI1049.RequiredFaction =1
QI1049.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1049.Color =0
QI1049.Creature =[1031,-1,-1,-1]
QI1049.CreatureCount =[30,-1,-1,-1]
QI1049.Repeat =1
QI1049.RewardItem[0].Base =2902
QI1049.RewardItem[0].Append =[50,100,-1,-1,-1]
QI1049.RewardItem[0].BaseLv =2
QI1049.RewardItem[0].AppendLv =1
QI1049.RewardItem[0].Overlap =1
QI1049.RewardItem[0].Binding =1
QI1049.RewardItem[1].Base =2902
QI1049.RewardItem[1].Append =[50,130,-1,-1,-1]
QI1049.RewardItem[1].BaseLv =2
QI1049.RewardItem[1].AppendLv =1
QI1049.RewardItem[1].Overlap =1
QI1049.RewardItem[1].Binding =1
QR1049.QuestID =1049
QR1049.EXP =3500
QR1049.SkillPoint =2

# 1050
QI1050.QuestID =1050
QI1050.QuestSort =0
QI1050.PrevQuestId =1049
QI1050.NextQuestId =1051
QI1050.MinLevel =32
QI1050.RequiredFaction =1
QI1050.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1050.Color =0
QI1050.Repeat =1
QI1050.RequiredLevel =33
QR1050.QuestID =1050
QR1050.EXP =1000

# 1051
QI1051.QuestID =1051
QI1051.QuestSort =0
QI1051.PrevQuestId =1050
QI1051.NextQuestId =1052
QI1051.MinLevel =33
QI1051.RequiredFaction =1
QI1051.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1051.Color =0
QI1051.Item =[105,-1,-1,-1]
QI1051.ItemCount =[1,-1,-1,-1]
QI1051.ItemProbability =[8,-1,-1,-1]
QI1051.Repeat =1
QI1051.RewardMoney =2000
QR1051.QuestID =1051
QR1051.EXP =4000
QR1051.SkillPoint =2

# 1052
QI1052.QuestID =1052
QI1052.QuestSort =0
QI1052.PrevQuestId =1051
QI1052.NextQuestId =1053
QI1052.MinLevel =33
QI1052.RequiredFaction =1
QI1052.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1052.Color =0
QI1052.Repeat =1
QI1052.RewardItem[0].Base =2301
QI1052.RewardItem[0].Append =[110,180,-1,-1,-1]
QI1052.RewardItem[0].BaseLv =2
QI1052.RewardItem[0].AppendLv =2
QI1052.RewardItem[0].Overlap =1
QI1052.RewardItem[0].Binding =1
QI1052.RewardItem[1].Base =2401
QI1052.RewardItem[1].Append =[110,180,-1,-1,-1]
QI1052.RewardItem[1].BaseLv =2
QI1052.RewardItem[1].AppendLv =2
QI1052.RewardItem[1].Overlap =1
QI1052.RewardItem[1].Binding =1
QI1052.RewardItem[2].Base =2501
QI1052.RewardItem[2].Append =[60,180,-1,-1,-1]
QI1052.RewardItem[2].BaseLv =2
QI1052.RewardItem[2].AppendLv =2
QI1052.RewardItem[2].Overlap =1
QI1052.RewardItem[2].Binding =1
QR1052.QuestID =1052
QR1052.EXP =1100

# 1053
QI1053.QuestID =1053
QI1053.QuestSort =0
QI1053.PrevQuestId =1052
QI1053.NextQuestId =1054
QI1053.MinLevel =33
QI1053.RequiredFaction =1
QI1053.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1053.Color =0
QI1053.Repeat =1
QI1053.RewardMoney =2000
QR1053.QuestID =1053
QR1053.EXP =1500
QR1053.SkillPoint =1

# 1054
QI1054.QuestID =1054
QI1054.QuestSort =0
QI1054.PrevQuestId =1053
QI1054.NextQuestId =1055
QI1054.MinLevel =34
QI1054.RequiredFaction =1
QI1054.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1054.Color =0
QI1054.Repeat =1
QR1054.QuestID =1054
QR1054.EXP =1000

# 1055
QI1055.QuestID =1055
QI1055.QuestSort =0
QI1055.PrevQuestId =1054
QI1055.NextQuestId =1056
QI1055.MinLevel =34
QI1055.RequiredFaction =1
QI1055.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1055.Color =0
QI1055.Repeat =1
QR1055.QuestID =1055
QR1055.EXP =1000

# 1056
QI1056.QuestID =1056
QI1056.QuestSort =0
QI1056.PrevQuestId =1055
QI1056.NextQuestId =1057
QI1056.MinLevel =34
QI1056.RequiredFaction =1
QI1056.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1056.Color =0
QI1056.Repeat =1
QI1056.RequiredLevel =35
QR1056.QuestID =1056
QR1056.EXP =1200

# 1057
QI1057.QuestID =1057
QI1057.QuestSort =0
QI1057.PrevQuestId =1056
QI1057.NextQuestId =1058
QI1057.MinLevel =35
QI1057.RequiredFaction =1
QI1057.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1057.Color =0
QI1057.Item =[106,-1,-1,-1]
QI1057.ItemCount =[3,-1,-1,-1]
QI1057.ItemProbability =[15,-1,-1,-1]
QI1057.Repeat =1
QR1057.QuestID =1057
QR1057.EXP =3000
QR1057.SkillPoint =2

# 1058
QI1058.QuestID =1058
QI1058.QuestSort =0
QI1058.PrevQuestId =1057
QI1058.NextQuestId =1059
QI1058.MinLevel =35
QI1058.RequiredFaction =1
QI1058.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1058.Color =0
QI1058.Repeat =1
QR1058.QuestID =1058
QR1058.EXP =1000

# 1059
QI1059.QuestID =1059
QI1059.QuestSort =0
QI1059.PrevQuestId =1058
QI1059.NextQuestId =1060
QI1059.MinLevel =36
QI1059.RequiredFaction =1
QI1059.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1059.Color =0
QI1059.Repeat =1
QI1059.RewardItem[0].Base =3203
QI1059.RewardItem[0].Append =[60,130,-1,-1,-1]
QI1059.RewardItem[0].BaseLv =2
QI1059.RewardItem[0].AppendLv =2
QI1059.RewardItem[0].Overlap =1
QI1059.RewardItem[0].Binding =1
QI1059.RewardItem[1].Base =3203
QI1059.RewardItem[1].Append =[90,130,-1,-1,-1]
QI1059.RewardItem[1].BaseLv =2
QI1059.RewardItem[1].AppendLv =2
QI1059.RewardItem[1].Overlap =1
QI1059.RewardItem[1].Binding =1
QR1059.QuestID =1059
QR1059.EXP =1200

# 1060
QI1060.QuestID =1060
QI1060.QuestSort =0
QI1060.PrevQuestId =1059
QI1060.NextQuestId =1061
QI1060.MinLevel =36
QI1060.RequiredFaction =1
QI1060.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1060.Color =0
QI1060.Repeat =1
QI1060.RewardMoney =2000
QR1060.QuestID =1060
QR1060.EXP =1500

# 1061
QI1061.QuestID =1061
QI1061.QuestSort =0
QI1061.PrevQuestId =1060
QI1061.NextQuestId =1062
QI1061.MinLevel =37
QI1061.RequiredFaction =1
QI1061.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1061.Color =0
QI1061.Repeat =1
QI1061.RequiredLevel =37
QR1061.QuestID =1061
QR1061.EXP =1200

# 1062
QI1062.QuestID =1062
QI1062.QuestSort =0
QI1062.PrevQuestId =1061
QI1062.NextQuestId =1063
QI1062.MinLevel =37
QI1062.RequiredFaction =1
QI1062.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1062.Color =0
QI1062.Creature =[1033,-1,-1,-1]
QI1062.CreatureCount =[35,-1,-1,-1]
QI1062.Repeat =1
QI1062.RewardItem[0].Base =1003
QI1062.RewardItem[0].Append =[0,40,150,-1,-1]
QI1062.RewardItem[0].BaseLv =2
QI1062.RewardItem[0].AppendLv =1
QI1062.RewardItem[0].Overlap =1
QI1062.RewardItem[0].Binding =1
QI1062.RewardItem[1].Base =1403
QI1062.RewardItem[1].Append =[0,40,150,-1,-1]
QI1062.RewardItem[1].BaseLv =2
QI1062.RewardItem[1].AppendLv =1
QI1062.RewardItem[1].Overlap =1
QI1062.RewardItem[1].Binding =1
QI1062.RewardItem[2].Base =1703
QI1062.RewardItem[2].Append =[20,40,160,-1,-1]
QI1062.RewardItem[2].BaseLv =2
QI1062.RewardItem[2].AppendLv =1
QI1062.RewardItem[2].Overlap =1
QI1062.RewardItem[2].Binding =1
QI1062.RewardItem[3].Base =1803
QI1062.RewardItem[3].Append =[20,40,160,-1,-1]
QI1062.RewardItem[3].BaseLv =2
QI1062.RewardItem[3].AppendLv =1
QI1062.RewardItem[3].Overlap =1
QI1062.RewardItem[3].Binding =1
QR1062.QuestID =1062
QR1062.EXP =5000
QR1062.SkillPoint =3

# 1063
QI1063.QuestID =1063
QI1063.QuestSort =0
QI1063.PrevQuestId =1062
QI1063.NextQuestId =1064
QI1063.MinLevel =38
QI1063.RequiredFaction =1
QI1063.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1063.Color =0
QI1063.Repeat =1
QI1063.RequiredLevel =39
QR1063.QuestID =1063
QR1063.EXP =1300

# 1064
QI1064.QuestID =1064
QI1064.QuestSort =0
QI1064.PrevQuestId =1063
QI1064.NextQuestId =1065
QI1064.MinLevel =39
QI1064.RequiredFaction =1
QI1064.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1064.Color =0
QI1064.Creature =[1035,-1,-1,-1]
QI1064.CreatureCount =[35,-1,-1,-1]
QI1064.Repeat =1
QR1064.QuestID =1064
QR1064.EXP =6000
QR1064.SkillPoint =3

# 1065
QI1065.QuestID =1065
QI1065.QuestSort =0
QI1065.PrevQuestId =1064
QI1065.NextQuestId =1066
QI1065.MinLevel =40
QI1065.RequiredFaction =1
QI1065.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1065.Color =0
QI1065.Repeat =1
QR1065.QuestID =1065
QR1065.EXP =1300

# 1066
QI1066.QuestID =1066
QI1066.QuestSort =0
QI1066.PrevQuestId =1065
QI1066.NextQuestId =1067
QI1066.MinLevel =41
QI1066.RequiredFaction =1
QI1066.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1066.Color =0
QI1066.Repeat =1
QI1066.RewardItem[0].Base =5800
QI1066.RewardItem[0].Overlap =1
QI1066.RewardItem[0].Binding =1
QR1066.QuestID =1066
QR1066.EXP =1300

# 1067
QI1067.QuestID =1067
QI1067.QuestSort =0
QI1067.PrevQuestId =1066
QI1067.NextQuestId =1068
QI1067.MinLevel =42
QI1067.RequiredFaction =1
QI1067.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1067.Color =0
QI1067.Repeat =1
QI1067.RequiredLevel =44
QR1067.QuestID =1067
QR1067.EXP =1500

# 1068
QI1068.QuestID =1068
QI1068.QuestSort =0
QI1068.PrevQuestId =1067
QI1068.NextQuestId =1069
QI1068.MinLevel =44
QI1068.RequiredFaction =1
QI1068.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1068.Color =0
QI1068.Creature =[1038,-1,-1,-1]
QI1068.CreatureCount =[40,-1,-1,-1]
QI1068.Repeat =1
QI1068.RewardItem[0].Base =4210
QI1068.RewardItem[0].Overlap =5
QI1068.RewardItem[0].Binding =1
QI1068.RewardItem[1].Base =4220
QI1068.RewardItem[1].Overlap =5
QI1068.RewardItem[1].Binding =1
QR1068.QuestID =1068
QR1068.EXP =3000
QR1068.SkillPoint =2

# 1069
QI1069.QuestID =1069
QI1069.QuestSort =0
QI1069.PrevQuestId =1068
QI1069.NextQuestId =1070
QI1069.MinLevel =45
QI1069.RequiredFaction =1
QI1069.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1069.Color =0
QI1069.Repeat =1
QI1069.RequiredLevel =47
QR1069.QuestID =1069
QR1069.EXP =3000
QR1069.SkillPoint =2

# 1070
QI1070.QuestID =1070
QI1070.QuestSort =0
QI1070.PrevQuestId =1069
QI1070.NextQuestId =1071
QI1070.MinLevel =47
QI1070.RequiredFaction =1
QI1070.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1070.Color =0
QI1070.Creature =[1051,-1,-1,-1]
QI1070.CreatureCount =[45,-1,-1,-1]
QI1070.Repeat =1
QI1070.RewardItem[0].Base =4201
QI1070.RewardItem[0].Overlap =1
QI1070.RewardItem[0].Binding =1
QI1070.RewardItem[1].Base =4211
QI1070.RewardItem[1].Overlap =2
QI1070.RewardItem[1].Binding =1
QI1070.RewardItem[2].Base =4221
QI1070.RewardItem[2].Overlap =2
QI1070.RewardItem[2].Binding =1
QR1070.QuestID =1070
QR1070.EXP =6000
QR1070.SkillPoint =3

# 1071
QI1071.QuestID =1071
QI1071.QuestSort =0
QI1071.PrevQuestId =1070
QI1071.NextQuestId =1072
QI1071.MinLevel =48
QI1071.RequiredFaction =1
QI1071.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1071.Color =0
QI1071.Repeat =1
QR1071.QuestID =1071
QR1071.EXP =2000

# 1072
QI1072.QuestID =1072
QI1072.QuestSort =0
QI1072.PrevQuestId =1071
QI1072.NextQuestId =1073
QI1072.MinLevel =49
QI1072.RequiredFaction =1
QI1072.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1072.Color =0
QI1072.Repeat =1
QR1072.QuestID =1072
QR1072.EXP =1600

# 1073
QI1073.QuestID =1073
QI1073.QuestSort =0
QI1073.PrevQuestId =1072
QI1073.NextQuestId =1074
QI1073.MinLevel =50
QI1073.RequiredFaction =1
QI1073.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1073.Color =0
QI1073.Repeat =1
QI1073.RewardItem[0].Base =2104
QI1073.RewardItem[0].Append =[11,-1,-1,-1,-1]
QI1073.RewardItem[0].BaseLv =2
QI1073.RewardItem[0].AppendLv =4
QI1073.RewardItem[0].Overlap =1
QI1073.RewardItem[0].Binding =1
QI1073.RewardItem[1].Base =2204
QI1073.RewardItem[1].Append =[31,-1,-1,-1,-1]
QI1073.RewardItem[1].BaseLv =2
QI1073.RewardItem[1].AppendLv =4
QI1073.RewardItem[1].Overlap =1
QI1073.RewardItem[1].Binding =1
QR1073.QuestID =1073
QR1073.EXP =1600

# 1074
QI1074.QuestID =1074
QI1074.QuestSort =0
QI1074.PrevQuestId =1073
QI1074.NextQuestId =1075
QI1074.MinLevel =51
QI1074.RequiredFaction =1
QI1074.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1074.Color =0
QI1074.Repeat =1
QI1074.RequiredLevel =52
QR1074.QuestID =1074
QR1074.EXP =1800

# 1075
QI1075.QuestID =1075
QI1075.QuestSort =0
QI1075.PrevQuestId =1074
QI1075.NextQuestId =1076
QI1075.MinLevel =52
QI1075.RequiredFaction =1
QI1075.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1075.Color =0
QI1075.Item =[107,-1,-1,-1]
QI1075.ItemCount =[10,-1,-1,-1]
QI1075.ItemProbability =[25,-1,-1,-1]
QI1075.Repeat =1
QR1075.QuestID =1075
QR1075.EXP =8000
QR1075.SkillPoint =4

# 1076
QI1076.QuestID =1076
QI1076.QuestSort =0
QI1076.PrevQuestId =1075
QI1076.NextQuestId =1077
QI1076.MinLevel =53
QI1076.RequiredFaction =1
QI1076.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1076.Color =0
QI1076.Repeat =1
QI1076.RewardItem[0].Base =2302
QI1076.RewardItem[0].Append =[131,-1,-1,-1,-1]
QI1076.RewardItem[0].BaseLv =2
QI1076.RewardItem[0].AppendLv =3
QI1076.RewardItem[0].Overlap =1
QI1076.RewardItem[0].Binding =1
QI1076.RewardItem[1].Base =2402
QI1076.RewardItem[1].Append =[141,-1,-1,-1,-1]
QI1076.RewardItem[1].BaseLv =2
QI1076.RewardItem[1].AppendLv =3
QI1076.RewardItem[1].Overlap =1
QI1076.RewardItem[1].Binding =1
QI1076.RewardItem[2].Base =2502
QI1076.RewardItem[2].Append =[40,60,-1,-1,-1]
QI1076.RewardItem[2].BaseLv =2
QI1076.RewardItem[2].AppendLv =2
QI1076.RewardItem[2].Overlap =1
QI1076.RewardItem[2].Binding =1
QR1076.QuestID =1076
QR1076.EXP =1800

# 1077
QI1077.QuestID =1077
QI1077.QuestSort =0
QI1077.PrevQuestId =1076
QI1077.NextQuestId =1078
QI1077.MinLevel =54
QI1077.RequiredFaction =1
QI1077.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1077.Color =0
QI1077.Repeat =1
QR1077.QuestID =1077
QR1077.EXP =1900

# 1078
QI1078.QuestID =1078
QI1078.QuestSort =0
QI1078.PrevQuestId =1077
QI1078.NextQuestId =1079
QI1078.MinLevel =55
QI1078.RequiredFaction =1
QI1078.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1078.Color =0
QI1078.Repeat =1
QI1078.RewardItem[0].Base =2602
QI1078.RewardItem[0].Append =[70,120,151,-1,-1]
QI1078.RewardItem[0].BaseLv =2
QI1078.RewardItem[0].AppendLv =2
QI1078.RewardItem[0].Overlap =1
QI1078.RewardItem[0].Binding =1
QR1078.QuestID =1078
QR1078.EXP =2000

# 1079
QI1079.QuestID =1079
QI1079.QuestSort =0
QI1079.PrevQuestId =1078
QI1079.NextQuestId =1080
QI1079.MinLevel =56
QI1079.RequiredFaction =1
QI1079.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1079.Color =0
QI1079.Repeat =1
QI1079.RequiredLevel =57
QR1079.QuestID =1079
QR1079.EXP =3000

# 1080
QI1080.QuestID =1080
QI1080.QuestSort =0
QI1080.PrevQuestId =1079
QI1080.NextQuestId =1081
QI1080.MinLevel =57
QI1080.RequiredFaction =1
QI1080.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1080.Color =0
QI1080.Creature =[1055,-1,-1,-1]
QI1080.CreatureCount =[50,-1,-1,-1]
QI1080.Repeat =1
QI1080.RewardItem[0].Base =2702
QI1080.RewardItem[0].Append =[70,120,170,-1,-1]
QI1080.RewardItem[0].BaseLv =2
QI1080.RewardItem[0].AppendLv =2
QI1080.RewardItem[0].Overlap =1
QI1080.RewardItem[0].Binding =1
QR1080.QuestID =1080
QR1080.EXP =10000
QR1080.SkillPoint =4

# 1081
QI1081.QuestID =1081
QI1081.QuestSort =0
QI1081.PrevQuestId =1080
QI1081.NextQuestId =1082
QI1081.MinLevel =58
QI1081.RequiredFaction =1
QI1081.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1081.Color =0
QI1081.Repeat =1
QR1081.QuestID =1081
QR1081.EXP =2000

# 1082
QI1082.QuestID =1082
QI1082.QuestSort =0
QI1082.PrevQuestId =1081
QI1082.NextQuestId =1083
QI1082.MinLevel =59
QI1082.RequiredFaction =1
QI1082.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1082.Color =0
QI1082.Repeat =1
QI1082.RequiredLevel =60
QR1082.QuestID =1082
QR1082.EXP =2100

# 1083
QI1083.QuestID =1083
QI1083.QuestSort =0
QI1083.PrevQuestId =1082
QI1083.NextQuestId =1084
QI1083.MinLevel =60
QI1083.RequiredFaction =1
QI1083.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1083.Color =0
QI1083.Item =[108,-1,-1,-1]
QI1083.ItemCount =[20,-1,-1,-1]
QI1083.ItemProbability =[35,-1,-1,-1]
QI1083.Repeat =1
QR1083.QuestID =1083
QR1083.EXP =12000
QR1083.SkillPoint =4

# 1084
QI1084.QuestID =1084
QI1084.QuestSort =0
QI1084.PrevQuestId =1083
QI1084.NextQuestId =1085
QI1084.MinLevel =62
QI1084.RequiredFaction =1
QI1084.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1084.Color =0
QI1084.Repeat =1
QI1084.RewardItem[0].Base =3206
QI1084.RewardItem[0].Append =[1,80,-1,-1,-1]
QI1084.RewardItem[0].BaseLv =2
QI1084.RewardItem[0].AppendLv =3
QI1084.RewardItem[0].Overlap =1
QI1084.RewardItem[0].Binding =1
QI1084.RewardItem[1].Base =3206
QI1084.RewardItem[1].Append =[21,90,-1,-1,-1]
QI1084.RewardItem[1].BaseLv =2
QI1084.RewardItem[1].AppendLv =3
QI1084.RewardItem[1].Overlap =1
QI1084.RewardItem[1].Binding =1
QR1084.QuestID =1084
QR1084.EXP =3000
QR1084.SkillPoint =1

# 1085
QI1085.QuestID =1085
QI1085.QuestSort =0
QI1085.PrevQuestId =1084
QI1085.NextQuestId =1086
QI1085.MinLevel =64
QI1085.RequiredFaction =1
QI1085.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1085.Color =0
QI1085.Repeat =1
QR1085.QuestID =1085
QR1085.EXP =2200

# 1086
QI1086.QuestID =1086
QI1086.QuestSort =0
QI1086.PrevQuestId =1085
QI1086.NextQuestId =1087
QI1086.MinLevel =66
QI1086.RequiredFaction =1
QI1086.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1086.Color =0
QI1086.Money =100
QI1086.Repeat =1
QI1086.RequiredLevel =68
QR1086.QuestID =1086
QR1086.EXP =2400

# 1087
QI1087.QuestID =1087
QI1087.QuestSort =0
QI1087.PrevQuestId =1086
QI1087.NextQuestId =1088
QI1087.MinLevel =68
QI1087.RequiredFaction =1
QI1087.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1087.Color =0
QI1087.Item =[109,-1,-1,-1]
QI1087.ItemCount =[20,-1,-1,-1]
QI1087.ItemProbability =[35,-1,-1,-1]
QI1087.Repeat =1
QR1087.QuestID =1087
QR1087.EXP =15000
QR1087.SkillPoint =5

# 1088
QI1088.QuestID =1088
QI1088.QuestSort =0
QI1088.PrevQuestId =1087
QI1088.NextQuestId =1089
QI1088.MinLevel =70
QI1088.RequiredFaction =1
QI1088.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1088.Color =0
QI1088.Repeat =1
QR1088.QuestID =1088
QR1088.EXP =4000
QR1088.SkillPoint =1

# 1089
QI1089.QuestID =1089
QI1089.QuestSort =0
QI1089.PrevQuestId =1088
QI1089.NextQuestId =1090
QI1089.MinLevel =72
QI1089.RequiredFaction =1
QI1089.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1089.Color =0
QI1089.Repeat =1
QR1089.QuestID =1089
QR1089.EXP =5000

# 1090
QI1090.QuestID =1090
QI1090.QuestSort =0
QI1090.PrevQuestId =1089
QI1090.NextQuestId =1091
QI1090.MinLevel =74
QI1090.RequiredFaction =1
QI1090.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1090.Color =0
QI1090.Repeat =1
QR1090.QuestID =1090
QR1090.EXP =5000

# 1091
QI1091.QuestID =1091
QI1091.QuestSort =0
QI1091.PrevQuestId =1090
QI1091.NextQuestId =1092
QI1091.MinLevel =75
QI1091.RequiredFaction =1
QI1091.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1091.Color =0
QI1091.Repeat =1
QR1091.QuestID =1091
QR1091.EXP =3000

# 1092
QI1092.QuestID =1092
QI1092.QuestSort =0
QI1092.PrevQuestId =1091
QI1092.NextQuestId =1093
QI1092.MinLevel =77
QI1092.RequiredFaction =1
QI1092.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1092.Color =0
QI1092.Repeat =1
QI1092.RequiredLevel =79
QR1092.QuestID =1092
QR1092.EXP =3500

# 1093
QI1093.QuestID =1093
QI1093.QuestSort =0
QI1093.PrevQuestId =1092
QI1093.NextQuestId =1094
QI1093.MinLevel =79
QI1093.RequiredFaction =1
QI1093.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1093.Color =0
QI1093.Creature =[1072,-1,-1,-1]
QI1093.CreatureCount =[70,-1,-1,-1]
QI1093.Repeat =1
QI1093.RewardItem[0].Base =2503
QI1093.RewardItem[0].Append =[131,141,-1,-1,-1]
QI1093.RewardItem[0].BaseLv =1
QI1093.RewardItem[0].AppendLv =1
QI1093.RewardItem[0].Overlap =1
QI1093.RewardItem[0].Binding =1
QR1093.QuestID =1093
QR1093.EXP =20000
QR1093.SkillPoint =5

# 1094
QI1094.QuestID =1094
QI1094.QuestSort =0
QI1094.PrevQuestId =1093
QI1094.NextQuestId =1095
QI1094.MinLevel =80
QI1094.RequiredFaction =1
QI1094.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1094.Color =0
QI1094.Repeat =1
QI1094.RequiredLevel =82
QR1094.QuestID =1094
QR1094.EXP =4000

# 1095
QI1095.QuestID =1095
QI1095.QuestSort =0
QI1095.PrevQuestId =1094
QI1095.NextQuestId =1096
QI1095.MinLevel =82
QI1095.RequiredFaction =1
QI1095.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1095.Color =0
QI1095.Creature =[1074,-1,-1,-1]
QI1095.CreatureCount =[75,-1,-1,-1]
QI1095.Repeat =1
QI1095.RewardItem[0].Base =3004
QI1095.RewardItem[0].Append =[12,32,-1,-1,-1]
QI1095.RewardItem[0].BaseLv =2
QI1095.RewardItem[0].AppendLv =2
QI1095.RewardItem[0].Overlap =1
QI1095.RewardItem[0].Binding =1
QR1095.QuestID =1095
QR1095.EXP =25000
QR1095.SkillPoint =4

# 1096
QI1096.QuestID =1096
QI1096.QuestSort =0
QI1096.PrevQuestId =1095
QI1096.NextQuestId =1097
QI1096.MinLevel =85
QI1096.RequiredFaction =1
QI1096.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1096.Color =0
QI1096.Repeat =1
QI1096.RequiredLevel =87
QR1096.QuestID =1096
QR1096.EXP =5000

# 1097
QI1097.QuestID =1097
QI1097.QuestSort =0
QI1097.PrevQuestId =1096
QI1097.NextQuestId =1098
QI1097.MinLevel =87
QI1097.RequiredFaction =1
QI1097.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1097.Color =0
QI1097.Creature =[1075,-1,-1,-1]
QI1097.CreatureCount =[75,-1,-1,-1]
QI1097.Repeat =1
QI1097.RewardItem[0].Base =3104
QI1097.RewardItem[0].Append =[102,142,170,-1,-1]
QI1097.RewardItem[0].BaseLv =3
QI1097.RewardItem[0].AppendLv =1
QI1097.RewardItem[0].Overlap =1
QI1097.RewardItem[0].Binding =1
QI1097.RewardItem[1].Base =3104
QI1097.RewardItem[1].Append =[50,70,120,-1,-1]
QI1097.RewardItem[1].BaseLv =3
QI1097.RewardItem[1].AppendLv =1
QI1097.RewardItem[1].Overlap =1
QI1097.RewardItem[1].Binding =1
QR1097.QuestID =1097
QR1097.EXP =30000
QR1097.SkillPoint =5

# 1098
QI1098.QuestID =1098
QI1098.QuestSort =0
QI1098.PrevQuestId =1097
QI1098.NextQuestId =1099
QI1098.MinLevel =89
QI1098.RequiredFaction =1
QI1098.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1098.Color =0
QI1098.Repeat =1
QR1098.QuestID =1098
QR1098.EXP =5000

# 1099
QI1099.QuestID =1099
QI1099.QuestSort =0
QI1099.PrevQuestId =1098
QI1099.NextQuestId =1100
QI1099.MinLevel =90
QI1099.RequiredFaction =1
QI1099.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1099.Color =0
QI1099.Repeat =1
QI1099.RequiredLevel =91
QR1099.QuestID =1099
QR1099.EXP =5000

# 1100
QI1100.QuestID =1100
QI1100.QuestSort =0
QI1100.PrevQuestId =1099
QI1100.NextQuestId =-1
QI1100.MinLevel =91
QI1100.RequiredFaction =1
QI1100.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1100.Color =0
QI1100.Creature =[1091,-1,-1,-1]
QI1100.CreatureCount =[80,-1,-1,-1]
QI1100.Repeat =1
QI1100.RewardItem[0].Base =4232
QI1100.RewardItem[0].Overlap =1
QI1100.RewardItem[0].Binding =1
QR1100.QuestID =1100
QR1100.EXP =35000
QR1100.SkillPoint =5

# 1101
QI1101.QuestID =1101
QI1101.QuestSort =1
QI1101.NextQuestId =1102
QI1101.MinLevel =10
QI1101.RequiredFaction =1
QI1101.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1101.Color =0
QI1101.Creature =[1012,-1,-1,-1]
QI1101.CreatureCount =[20,-1,-1,-1]
QI1101.Repeat =1
QR1101.QuestID =1101
QR1101.EXP =600

# 1102
QI1102.QuestID =1102
QI1102.QuestSort =1
QI1102.PrevQuestId =1101
QI1102.NextQuestId =1103
QI1102.MinLevel =40
QI1102.RequiredFaction =1
QI1102.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1102.Color =0
QI1102.Creature =[1034,-1,-1,-1]
QI1102.CreatureCount =[30,-1,-1,-1]
QI1102.Repeat =1
QR1102.QuestID =1102
QR1102.EXP =7800
QR1102.SkillPoint =2

# 1103
QI1103.QuestID =1103
QI1103.QuestSort =1
QI1103.PrevQuestId =1102
QI1103.NextQuestId =1104
QI1103.MinLevel =50
QI1103.RequiredFaction =1
QI1103.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1103.Color =1
QI1103.Creature =[1054,-1,-1,-1]
QI1103.CreatureCount =[50,-1,-1,-1]
QI1103.Repeat =1
QR1103.QuestID =1103
QR1103.EXP =30000
QR1103.SkillPoint =8

# 1104
QI1104.QuestID =1104
QI1104.QuestSort =1
QI1104.PrevQuestId =1103
QI1104.NextQuestId =1105
QI1104.MinLevel =80
QI1104.RequiredFaction =1
QI1104.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1104.Color =0
QI1104.Creature =[1074,-1,-1,-1]
QI1104.CreatureCount =[70,-1,-1,-1]
QI1104.Repeat =1
QR1104.QuestID =1104
QR1104.EXP =50000
QR1104.SkillPoint =8

# 1105
QI1105.QuestID =1105
QI1105.QuestSort =1
QI1105.PrevQuestId =1104
QI1105.NextQuestId =1106
QI1105.MinLevel =90
QI1105.RequiredFaction =1
QI1105.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1105.Color =1
QI1105.Creature =[1091,-1,-1,-1]
QI1105.CreatureCount =[90,-1,-1,-1]
QI1105.Repeat =1
QR1105.QuestID =1105
QR1105.EXP =95000
QR1105.SkillPoint =14

# 1106
QI1106.QuestID =1106
QI1106.QuestSort =1
QI1106.PrevQuestId =1105
QI1106.MinLevel =100
QI1106.RequiredFaction =1
QI1106.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1106.Color =2
QI1106.Creature =[1094,-1,-1,-1]
QI1106.CreatureCount =[100,-1,-1,-1]
QI1106.Repeat =1
QR1106.QuestID =1106
QR1106.EXP =140000
QR1106.SkillPoint =20

# 1107
QI1107.QuestID =1107
QI1107.QuestSort =1
QI1107.NextQuestId =1108
QI1107.MinLevel =20
QI1107.RequiredFaction =1
QI1107.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1107.Color =0
QI1107.Repeat =1
QI1107.RewardMoney =1000
QR1107.QuestID =1107
QR1107.EXP =500

# 1108
QI1108.QuestID =1108
QI1108.QuestSort =1
QI1108.PrevQuestId =1107
QI1108.NextQuestId =1109
QI1108.MinLevel =22
QI1108.RequiredFaction =1
QI1108.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1108.Color =0
QI1108.Repeat =1
QI1108.RewardMoney =1000
QR1108.QuestID =1108
QR1108.EXP =1000

# 1109
QI1109.QuestID =1109
QI1109.QuestSort =1
QI1109.PrevQuestId =1108
QI1109.MinLevel =40
QI1109.RequiredFaction =1
QI1109.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1109.Color =1
QI1109.Item =[110,-1,-1,-1]
QI1109.ItemCount =[1,-1,-1,-1]
QI1109.ItemProbability =[8,-1,-1,-1]
QI1109.Repeat =1
QR1109.QuestID =1109
QR1109.EXP =12000
QR1109.SkillPoint =4

# 1110
QI1110.QuestID =1110
QI1110.QuestSort =1
QI1110.NextQuestsId =1111,-1
QI1110.MinLevel =50
QI1110.RequiredFaction =1
QI1110.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1110.Color =0
QI1110.Creature =[1055,-1,-1,-1]
QI1110.CreatureCount =[50,-1,-1,-1]
QI1110.Repeat =1
QR1110.QuestID =1110
QR1110.EXP =21000
QR1110.SkillPoint =5

# 1111
QI1111.QuestID =1111
QI1111.QuestSort =1
QI1111.PrevQuestId =1110
QI1111.NextQuestId =1112
QI1111.MinLevel =60
QI1111.RequiredFaction =1
QI1111.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1111.Color =0
QI1111.Repeat =1
QR1111.QuestID =1111
QR1111.EXP =2000

# 1112
QI1112.QuestID =1112
QI1112.QuestSort =1
QI1112.PrevQuestId =1111
QI1112.MinLevel =75
QI1112.RequiredFaction =1
QI1112.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1112.Color =1
QI1112.Creature =[1073,-1,-1,-1]
QI1112.CreatureCount =[70,-1,-1,-1]
QI1112.Repeat =1
QR1112.QuestID =1112
QR1112.EXP =64000
QR1112.SkillPoint =11

# 1113
QI1113.QuestID =1113
QI1113.QuestSort =1
QI1113.NextQuestId =1114
QI1113.MinLevel =100
QI1113.RequiredFaction =1
QI1113.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1113.Color =0
QI1113.Repeat =1
QR1113.QuestID =1113
QR1113.EXP =10000

# 1114
QI1114.QuestID =1114
QI1114.QuestSort =1
QI1114.PrevQuestId =1113
QI1114.NextQuestId =1115
QI1114.MinLevel =101
QI1114.RequiredFaction =1
QI1114.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1114.Color =0
QI1114.Repeat =1
QR1114.QuestID =1114
QR1114.EXP =20000

# 1115
QI1115.QuestID =1115
QI1115.QuestSort =1
QI1115.PrevQuestId =1114
QI1115.MinLevel =99
QI1115.RequiredFaction =1
QI1115.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1115.Color =1
QI1115.Item =[120,-1,-1,-1]
QI1115.ItemCount =[1,-1,-1,-1]
QI1115.ItemProbability =[8,-1,-1,-1]
QI1115.Repeat =1
QR1115.QuestID =1115
QR1115.EXP =30000
QR1115.SkillPoint =5

# 1116
QI1116.QuestID =1116
QI1116.QuestSort =2
QI1116.MinLevel =25
QI1116.RequiredFaction =1
QI1116.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1116.Color =2
QI1116.Creature =[1017,-1,-1,-1]
QI1116.CreatureCount =[1,-1,-1,-1]
QI1116.Repeat =1
QI1116.RewardMoney =2000
QR1116.QuestID =1116
QR1116.EXP =30000
QR1116.SkillPoint =12

# 1117
QI1117.QuestID =1117
QI1117.QuestSort =2
QI1117.MinLevel =36
QI1117.RequiredFaction =1
QI1117.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1117.Color =1
QI1117.Creature =[1037,-1,-1,-1]
QI1117.CreatureCount =[40,-1,-1,-1]
QI1117.Repeat =1
QI1117.RewardMoney =2000
QR1117.QuestID =1117
QR1117.EXP =22000
QR1117.SkillPoint =6

# 1118
QI1118.QuestID =1118
QI1118.QuestSort =2
QI1118.MinLevel =56
QI1118.RequiredFaction =1
QI1118.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1118.Color =2
QI1118.Creature =[1053,-1,-1,-1]
QI1118.CreatureCount =[1,-1,-1,-1]
QI1118.Repeat =1
QI1118.RewardMoney =5000
QR1118.QuestID =1118
QR1118.EXP =80000
QR1118.SkillPoint =20

# 1119
QI1119.QuestID =1119
QI1119.QuestSort =2
QI1119.MinLevel =70
QI1119.RequiredFaction =1
QI1119.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1119.Color =1
QI1119.Creature =[1070,-1,-1,-1]
QI1119.CreatureCount =[60,-1,-1,-1]
QI1119.Repeat =1
QI1119.RewardMoney =5000
QR1119.QuestID =1119
QR1119.EXP =50000
QR1119.SkillPoint =9

# 1120
QI1120.QuestID =1120
QI1120.QuestSort =2
QI1120.MinLevel =72
QI1120.RequiredFaction =1
QI1120.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1120.Color =1
QI1120.Creature =[1071,-1,-1,-1]
QI1120.CreatureCount =[70,-1,-1,-1]
QI1120.Repeat =1
QI1120.RewardMoney =6000
QR1120.QuestID =1120
QR1120.EXP =60000
QR1120.SkillPoint =11

# 1121
QI1121.QuestID =1121
QI1121.QuestSort =2
QI1121.MinLevel =90
QI1121.RequiredFaction =1
QI1121.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1121.Color =1
QI1121.Creature =[1092,-1,-1,-1]
QI1121.CreatureCount =[80,-1,-1,-1]
QI1121.Repeat =1
QI1121.RewardMoney =10000
QR1121.QuestID =1121
QR1121.EXP =110000
QR1121.SkillPoint =16

# 1122
QI1122.QuestID =1122
QI1122.QuestSort =2
QI1122.MinLevel =100
QI1122.RequiredFaction =1
QI1122.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1122.Color =3
QI1122.Creature =[1093,-1,-1,-1]
QI1122.CreatureCount =[1,-1,-1,-1]
QI1122.Repeat =1
QI1122.RewardMoney =20000
QR1122.QuestID =1122
QR1122.EXP =220000
QR1122.SkillPoint =30

# 1123
QI1123.QuestID =1123
QI1123.QuestSort =3
QI1123.MinLevel =10
QI1123.RequiredClass =0,1
QI1123.RequiredFaction =1
QI1123.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1123.Color =0
QI1123.Repeat =1
QI1123.RewardItem[0].Base =5011
QI1123.RewardItem[0].Overlap =1
QI1123.RewardItem[0].Binding =1
QI1123.RewardItem[1].Base =5027
QI1123.RewardItem[1].Overlap =1
QI1123.RewardItem[1].Binding =1
QI1123.RewardItem[2].Base =5211
QI1123.RewardItem[2].Overlap =1
QI1123.RewardItem[2].Binding =1
QI1123.RewardItem[3].Base =5240
QI1123.RewardItem[3].Overlap =1
QI1123.RewardItem[3].Binding =1
QR1123.QuestID =1123
QR1123.EXP =0

# 1124
QI1124.QuestID =1124
QI1124.QuestSort =3
QI1124.MinLevel =30
QI1124.RequiredClass =0,1
QI1124.RequiredFaction =1
QI1124.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1124.Color =0
QI1124.Repeat =1
QI1124.RewardItem[0].Base =5012
QI1124.RewardItem[0].Overlap =1
QI1124.RewardItem[0].Binding =1
QI1124.RewardItem[1].Base =5038
QI1124.RewardItem[1].Overlap =1
QI1124.RewardItem[1].Binding =1
QI1124.RewardItem[2].Base =5228
QI1124.RewardItem[2].Overlap =1
QI1124.RewardItem[2].Binding =1
QI1124.RewardItem[3].Base =5236
QI1124.RewardItem[3].Overlap =1
QI1124.RewardItem[3].Binding =1
QR1124.QuestID =1124
QR1124.EXP =0

# 1125
QI1125.QuestID =1125
QI1125.QuestSort =3
QI1125.MinLevel =50
QI1125.RequiredClass =0,1
QI1125.RequiredFaction =1
QI1125.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1125.Color =0
QI1125.Repeat =1
QI1125.RewardItem[0].Base =5023
QI1125.RewardItem[0].Overlap =1
QI1125.RewardItem[0].Binding =1
QI1125.RewardItem[1].Base =5004
QI1125.RewardItem[1].Overlap =1
QI1125.RewardItem[1].Binding =1
QI1125.RewardItem[2].Base =5231
QI1125.RewardItem[2].Overlap =1
QI1125.RewardItem[2].Binding =1
QI1125.RewardItem[3].Base =5204
QI1125.RewardItem[3].Overlap =1
QI1125.RewardItem[3].Binding =1
QR1125.QuestID =1125
QR1125.EXP =0

# 1126
QI1126.QuestID =1126
QI1126.QuestSort =3
QI1126.MinLevel =70
QI1126.RequiredClass =0,1
QI1126.RequiredFaction =1
QI1126.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1126.Color =0
QI1126.Repeat =1
QI1126.RewardItem[0].Base =5024
QI1126.RewardItem[0].Overlap =1
QI1126.RewardItem[0].Binding =1
QI1126.RewardItem[1].Base =5007
QI1126.RewardItem[1].Overlap =1
QI1126.RewardItem[1].Binding =1
QI1126.RewardItem[2].Base =5207
QI1126.RewardItem[2].Overlap =1
QI1126.RewardItem[2].Binding =1
QI1126.RewardItem[3].Base =5224
QI1126.RewardItem[3].Overlap =1
QI1126.RewardItem[3].Binding =1
QR1126.QuestID =1126
QR1126.EXP =0

# 1127
QI1127.QuestID =1127
QI1127.QuestSort =3
QI1127.MinLevel =90
QI1127.RequiredClass =0,1
QI1127.RequiredFaction =1
QI1127.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1127.Color =0
QI1127.Repeat =1
QI1127.RewardItem[0].Base =5008
QI1127.RewardItem[0].Overlap =1
QI1127.RewardItem[0].Binding =1
QI1127.RewardItem[1].Base =5036
QI1127.RewardItem[1].Overlap =1
QI1127.RewardItem[1].Binding =1
QI1127.RewardItem[2].Base =5208
QI1127.RewardItem[2].Overlap =1
QI1127.RewardItem[2].Binding =1
QI1127.RewardItem[3].Base =5239
QI1127.RewardItem[3].Overlap =1
QI1127.RewardItem[3].Binding =1
QR1127.QuestID =1127
QR1127.EXP =0

# 1128
QI1128.QuestID =1128
QI1128.QuestSort =3
QI1128.MinLevel =40
QI1128.RequiredClass =0,1
QI1128.RequiredFaction =1
QI1128.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1128.Color =0
QI1128.Repeat =1
QI1128.RewardItem[0].Base =5028
QI1128.RewardItem[0].Overlap =1
QI1128.RewardItem[0].Binding =1
QI1128.RewardItem[1].Base =5241
QI1128.RewardItem[1].Overlap =1
QI1128.RewardItem[1].Binding =1
QR1128.QuestID =1128
QR1128.EXP =0

# 1129
QI1129.QuestID =1129
QI1129.QuestSort =3
QI1129.MinLevel =10
QI1129.RequiredClass =2,3
QI1129.RequiredFaction =1
QI1129.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1129.Color =0
QI1129.Repeat =1
QI1129.RewardItem[0].Base =5411
QI1129.RewardItem[0].Overlap =1
QI1129.RewardItem[0].Binding =1
QI1129.RewardItem[1].Base =5400
QI1129.RewardItem[1].Overlap =1
QI1129.RewardItem[1].Binding =1
QI1129.RewardItem[2].Base =5605
QI1129.RewardItem[2].Overlap =1
QI1129.RewardItem[2].Binding =1
QI1129.RewardItem[3].Base =5610
QI1129.RewardItem[3].Overlap =1
QI1129.RewardItem[3].Binding =1
QR1129.QuestID =1129
QR1129.EXP =0

# 1130
QI1130.QuestID =1130
QI1130.QuestSort =3
QI1130.MinLevel =30
QI1130.RequiredClass =2,3
QI1130.RequiredFaction =1
QI1130.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1130.Color =0
QI1130.Repeat =1
QI1130.RewardItem[0].Base =5412
QI1130.RewardItem[0].Overlap =1
QI1130.RewardItem[0].Binding =1
QI1130.RewardItem[1].Base =5428
QI1130.RewardItem[1].Overlap =1
QI1130.RewardItem[1].Binding =1
QI1130.RewardItem[2].Base =5601
QI1130.RewardItem[2].Overlap =1
QI1130.RewardItem[2].Binding =1
QI1130.RewardItem[3].Base =5616
QI1130.RewardItem[3].Overlap =1
QI1130.RewardItem[3].Binding =1
QR1130.QuestID =1130
QR1130.EXP =0

# 1131
QI1131.QuestID =1131
QI1131.QuestSort =3
QI1131.MinLevel =50
QI1131.RequiredClass =2,3
QI1131.RequiredFaction =1
QI1131.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1131.Color =0
QI1131.Repeat =1
QI1131.RewardItem[0].Base =5433
QI1131.RewardItem[0].Overlap =1
QI1131.RewardItem[0].Binding =1
QI1131.RewardItem[1].Base =5423
QI1131.RewardItem[1].Overlap =1
QI1131.RewardItem[1].Binding =1
QI1131.RewardItem[2].Base =5646
QI1131.RewardItem[2].Overlap =1
QI1131.RewardItem[2].Binding =1
QI1131.RewardItem[3].Base =5635
QI1131.RewardItem[3].Overlap =1
QI1131.RewardItem[3].Binding =1
QR1131.QuestID =1131
QR1131.EXP =0

# 1132
QI1132.QuestID =1132
QI1132.QuestSort =3
QI1132.MinLevel =70
QI1132.RequiredClass =2,3
QI1132.RequiredFaction =1
QI1132.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1132.Color =0
QI1132.Repeat =1
QI1132.RewardItem[0].Base =5443
QI1132.RewardItem[0].Overlap =1
QI1132.RewardItem[0].Binding =1
QI1132.RewardItem[1].Base =5407
QI1132.RewardItem[1].Overlap =1
QI1132.RewardItem[1].Binding =1
QI1132.RewardItem[2].Base =5621
QI1132.RewardItem[2].Overlap =1
QI1132.RewardItem[2].Binding =1
QI1132.RewardItem[3].Base =5638
QI1132.RewardItem[3].Overlap =1
QI1132.RewardItem[3].Binding =1
QR1132.QuestID =1132
QR1132.EXP =0

# 1133
QI1133.QuestID =1133
QI1133.QuestSort =3
QI1133.MinLevel =90
QI1133.RequiredClass =2,3
QI1133.RequiredFaction =1
QI1133.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1133.Color =0
QI1133.Repeat =1
QI1133.RewardItem[0].Base =5408
QI1133.RewardItem[0].Overlap =1
QI1133.RewardItem[0].Binding =1
QI1133.RewardItem[1].Base =5431
QI1133.RewardItem[1].Overlap =1
QI1133.RewardItem[1].Binding =1
QI1133.RewardItem[2].Base =5639
QI1133.RewardItem[2].Overlap =1
QI1133.RewardItem[2].Binding =1
QI1133.RewardItem[3].Base =5619
QI1133.RewardItem[3].Overlap =1
QI1133.RewardItem[3].Binding =1
QR1133.QuestID =1133
QR1133.EXP =0

# 1134
QI1134.QuestID =1134
QI1134.QuestSort =3
QI1134.MinLevel =40
QI1134.RequiredClass =2,3
QI1134.RequiredFaction =1
QI1134.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1134.Color =0
QI1134.Repeat =1
QI1134.RewardItem[0].Base =5403
QI1134.RewardItem[0].Overlap =1
QI1134.RewardItem[0].Binding =1
QI1134.RewardItem[1].Base =5611
QI1134.RewardItem[1].Overlap =1
QI1134.RewardItem[1].Binding =1
QR1134.QuestID =1134
QR1134.EXP =0

# 1135
QI1135.QuestID =1135
QI1135.QuestSort =1
QI1135.NextQuestId =1136
QI1135.MinLevel =2
QI1135.RequiredFaction =1
QI1135.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1135.Color =0
QI1135.Repeat =1
QR1135.QuestID =1135
QR1135.EXP =100

# 1136
QI1136.QuestID =1136
QI1136.QuestSort =1
QI1136.PrevQuestId =1135
QI1136.NextQuestsId =1137,-1
QI1136.MinLevel =16
QI1136.RequiredFaction =1
QI1136.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1136.Color =0
QI1136.Creature =[1016,-1,-1,-1]
QI1136.CreatureCount =[20,-1,-1,-1]
QI1136.Repeat =1
QR1136.QuestID =1136
QR1136.EXP =1200

# 1137
QI1137.QuestID =1137
QI1137.QuestSort =1
QI1137.PrevQuestId =1136
QI1137.MinLevel =30
QI1137.RequiredFaction =1
QI1137.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1137.Color =0
QI1137.Repeat =1
QI1137.RewardMoney =1000
QR1137.QuestID =1137
QR1137.EXP =500

# 1138
QI1138.QuestID =1138
QI1138.QuestSort =1
QI1138.MinLevel =40
QI1138.RequiredFaction =1
QI1138.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1138.Color =0
QI1138.Item =[121,-1,-1,-1]
QI1138.ItemCount =[1,-1,-1,-1]
QI1138.ItemProbability =[8,-1,-1,-1]
QI1138.Repeat =1
QR1138.QuestID =1138
QR1138.EXP =6000
QR1138.SkillPoint =1

# 1139
QI1139.QuestID =1139
QI1139.QuestSort =1
QI1139.MinLevel =60
QI1139.RequiredFaction =1
QI1139.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1139.Color =0
QI1139.Repeat =1
QR1139.QuestID =1139
QR1139.EXP =5000

# 1140
QI1140.QuestID =1140
QI1140.QuestSort =4
QI1140.NextQuestId =1141
QI1140.MinLevel =10
QI1140.RequiredFaction =1
QI1140.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1140.Color =0
QI1140.Repeat =1
QR1140.QuestID =1140
QR1140.EXP =200

# 1141
QI1141.QuestID =1141
QI1141.QuestSort =4
QI1141.PrevQuestId =1140
QI1141.MinLevel =40
QI1141.MaxLevel =50
QI1141.RequiredFaction =1
QI1141.MinTime =[0,1,0,-1]
QI1141.MaxTime =[23,58,0,-1]
QI1141.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1141.Color =0
QI1141.Creature =[1034,-1,-1,-1]
QI1141.CreatureCount =[25,-1,-1,-1]
QI1141.Repeat =3
QR1141.QuestID =1141
QR1141.EXP =2500
QR1141.SkillPoint =3

# 1142
QI1142.QuestID =1142
QI1142.QuestSort =4
QI1142.MinLevel =52
QI1142.MaxLevel =70
QI1142.RequiredFaction =1
QI1142.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1142.Color =0
QI1142.Repeat =1
QR1142.QuestID =1142
QR1142.EXP =2000

# 1143
QI1143.QuestID =1143
QI1143.QuestSort =4
QI1143.MinLevel =80
QI1143.MaxLevel =98
QI1143.RequiredFaction =1
QI1143.MinTime =[0,1,0,-1]
QI1143.MaxTime =[23,58,0,-1]
QI1143.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1143.Color =0
QI1143.Creature =[1075,-1,-1,-1]
QI1143.CreatureCount =[80,-1,-1,-1]
QI1143.Repeat =3
QR1143.QuestID =1143
QR1143.EXP =30000
QR1143.SkillPoint =9

# 1144
QI1144.QuestID =1144
QI1144.QuestSort =4
QI1144.MinLevel =100
QI1144.MaxLevel =118
QI1144.RequiredFaction =1
QI1144.MinTime =[0,1,0,-1]
QI1144.MaxTime =[23,58,0,-1]
QI1144.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1144.Color =0
QI1144.Creature =[1118,-1,-1,-1]
QI1144.CreatureCount =[100,-1,-1,-1]
QI1144.Repeat =3
QR1144.QuestID =1144
QR1144.EXP =57000
QR1144.SkillPoint =14

# 1145
QI1145.QuestID =1145
QI1145.QuestSort =5
QI1145.MinLevel =30
QI1145.MaxLevel =40
QI1145.RequiredFaction =1
QI1145.MinTime =[0,1,0,-1]
QI1145.MaxTime =[23,58,0,-1]
QI1145.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1145.Color =0
QI1145.Item =[122,-1,-1,-1]
QI1145.ItemCount =[12,-1,-1,-1]
QI1145.ItemProbability =[20,-1,-1,-1]
QI1145.Repeat =3
QI1145.RewardMoney =1000
QR1145.QuestID =1145
QR1145.EXP =0

# 1146
QI1146.QuestID =1146
QI1146.QuestSort =5
QI1146.MinLevel =50
QI1146.MaxLevel =60
QI1146.RequiredFaction =1
QI1146.MinTime =[0,1,0,-1]
QI1146.MaxTime =[23,58,0,-1]
QI1146.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1146.Color =0
QI1146.Item =[123,-1,-1,-1]
QI1146.ItemCount =[12,-1,-1,-1]
QI1146.ItemProbability =[20,-1,-1,-1]
QI1146.Repeat =3
QI1146.RewardMoney =3000
QR1146.QuestID =1146
QR1146.EXP =0

# 1147
QI1147.QuestID =1147
QI1147.QuestSort =5
QI1147.MinLevel =76
QI1147.MaxLevel =86
QI1147.RequiredFaction =1
QI1147.MinTime =[0,1,0,-1]
QI1147.MaxTime =[23,58,0,-1]
QI1147.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1147.Color =0
QI1147.Item =[124,-1,-1,-1]
QI1147.ItemCount =[12,-1,-1,-1]
QI1147.ItemProbability =[20,-1,-1,-1]
QI1147.Repeat =3
QI1147.RewardMoney =4500
QR1147.QuestID =1147
QR1147.EXP =0

# 1148
QI1148.QuestID =1148
QI1148.QuestSort =5
QI1148.MinLevel =94
QI1148.MaxLevel =104
QI1148.RequiredFaction =1
QI1148.MinTime =[0,1,0,-1]
QI1148.MaxTime =[23,58,0,-1]
QI1148.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1148.Color =0
QI1148.Item =[125,-1,-1,-1]
QI1148.ItemCount =[12,-1,-1,-1]
QI1148.ItemProbability =[20,-1,-1,-1]
QI1148.Repeat =3
QI1148.RewardMoney =6000
QR1148.QuestID =1148
QR1148.EXP =0

# 1149
QI1149.QuestID =1149
QI1149.QuestSort =5
QI1149.MinLevel =102
QI1149.MaxLevel =112
QI1149.RequiredFaction =1
QI1149.MinTime =[0,1,0,-1]
QI1149.MaxTime =[23,58,0,-1]
QI1149.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1149.Color =0
QI1149.Item =[126,-1,-1,-1]
QI1149.ItemCount =[12,-1,-1,-1]
QI1149.ItemProbability =[20,-1,-1,-1]
QI1149.Repeat =3
QI1149.RewardMoney =8000
QR1149.QuestID =1149
QR1149.EXP =0

# 1150
QI1150.QuestID =1150
QI1150.QuestSort =5
QI1150.MinLevel =50
QI1150.MaxLevel =80
QI1150.RequiredFaction =1
QI1150.MinTime =[0,1,0,-1]
QI1150.MaxTime =[23,58,0,-1]
QI1150.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1150.Color =0
QI1150.Repeat =3
QI1150.RewardMoney =1000
QR1150.QuestID =1150
QR1150.EXP =0

# 1151
QI1151.QuestID =1151
QI1151.QuestSort =1
QI1151.MinLevel =2
QI1151.MaxLevel =6
QI1151.RequiredFaction =1
QI1151.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1151.Color =0
QI1151.Item =[127,-1,-1,-1]
QI1151.ItemCount =[10,-1,-1,-1]
QI1151.ItemProbability =[80,-1,-1,-1]
QI1151.Repeat =0
QI1151.RewardMoney =200
QR1151.QuestID =1151
QR1151.EXP =250

# 1152
QI1152.QuestID =1152
QI1152.QuestSort =1
QI1152.MinLevel =4
QI1152.MaxLevel =10
QI1152.RequiredFaction =1
QI1152.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1152.Color =0
QI1152.Item =[128,-1,-1,-1]
QI1152.ItemCount =[8,-1,-1,-1]
QI1152.ItemProbability =[60,-1,-1,-1]
QI1152.Repeat =0
QI1152.RewardMoney =300
QR1152.QuestID =1152
QR1152.EXP =280

# 1153
QI1153.QuestID =1153
QI1153.QuestSort =1
QI1153.MinLevel =8
QI1153.MaxLevel =16
QI1153.RequiredFaction =1
QI1153.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1153.Color =0
QI1153.Item =[129,-1,-1,-1]
QI1153.ItemCount =[5,-1,-1,-1]
QI1153.ItemProbability =[50,-1,-1,-1]
QI1153.Repeat =0
QI1153.RewardMoney =400
QR1153.QuestID =1153
QR1153.EXP =350

# 1154
QI1154.QuestID =1154
QI1154.QuestSort =1
QI1154.MinLevel =12
QI1154.MaxLevel =20
QI1154.RequiredFaction =1
QI1154.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1154.Color =0
QI1154.Creature =[1015,-1,-1,-1]
QI1154.CreatureCount =[20,-1,-1,-1]
QI1154.Repeat =0
QR1154.QuestID =1154
QR1154.EXP =750

# 1155
QI1155.QuestID =1155
QI1155.QuestSort =1
QI1155.MinLevel =20
QI1155.MaxLevel =30
QI1155.RequiredFaction =1
QI1155.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1155.Color =0
QI1155.Creature =[1019,-1,-1,-1]
QI1155.CreatureCount =[25,-1,-1,-1]
QI1155.Repeat =0
QR1155.QuestID =1155
QR1155.EXP =1700

# 1156
QI1156.QuestID =1156
QI1156.QuestSort =1
QI1156.MinLevel =30
QI1156.MaxLevel =44
QI1156.RequiredFaction =1
QI1156.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1156.Color =0
QI1156.Creature =[1031,-1,-1,-1]
QI1156.CreatureCount =[40,-1,-1,-1]
QI1156.Repeat =0
QR1156.QuestID =1156
QR1156.EXP =3200
QR1156.SkillPoint =1

# 1157
QI1157.QuestID =1157
QI1157.QuestSort =1
QI1157.MinLevel =38
QI1157.MaxLevel =52
QI1157.RequiredFaction =1
QI1157.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1157.Color =0
QI1157.Item =[130,-1,-1,-1]
QI1157.ItemCount =[10,-1,-1,-1]
QI1157.ItemProbability =[20,-1,-1,-1]
QI1157.Repeat =0
QR1157.QuestID =1157
QR1157.EXP =5000
QR1157.SkillPoint =1

# 1158
QI1158.QuestID =1158
QI1158.QuestSort =1
QI1158.MinLevel =46
QI1158.MaxLevel =56
QI1158.RequiredFaction =1
QI1158.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1158.Color =0
QI1158.Creature =[1050,-1,-1,-1]
QI1158.CreatureCount =[80,-1,-1,-1]
QI1158.Repeat =0
QR1158.QuestID =1158
QR1158.EXP =9000
QR1158.SkillPoint =2

# 1159
QI1159.QuestID =1159
QI1159.QuestSort =1
QI1159.MinLevel =50
QI1159.MaxLevel =60
QI1159.RequiredFaction =1
QI1159.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1159.Color =0
QI1159.Creature =[1052,-1,-1,-1]
QI1159.CreatureCount =[100,-1,-1,-1]
QI1159.Repeat =0
QR1159.QuestID =1159
QR1159.EXP =12000
QR1159.SkillPoint =3

# 1160
QI1160.QuestID =1160
QI1160.QuestSort =1
QI1160.MinLevel =54
QI1160.MaxLevel =66
QI1160.RequiredFaction =1
QI1160.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1160.Color =0
QI1160.Creature =[1054,-1,-1,-1]
QI1160.CreatureCount =[120,-1,-1,-1]
QI1160.Repeat =0
QR1160.QuestID =1160
QR1160.EXP =15000
QR1160.SkillPoint =3

# 1161
QI1161.QuestID =1161
QI1161.QuestSort =1
QI1161.MinLevel =68
QI1161.MaxLevel =84
QI1161.RequiredFaction =1
QI1161.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1161.Color =0
QI1161.Creature =[1071,-1,-1,-1]
QI1161.CreatureCount =[120,-1,-1,-1]
QI1161.Repeat =0
QR1161.QuestID =1161
QR1161.EXP =19000
QR1161.SkillPoint =3

# 1162
QI1162.QuestID =1162
QI1162.QuestSort =1
QI1162.MinLevel =70
QI1162.MaxLevel =86
QI1162.RequiredFaction =1
QI1162.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1162.Color =0
QI1162.Item =[131,-1,-1,-1]
QI1162.ItemCount =[12,-1,-1,-1]
QI1162.ItemProbability =[10,-1,-1,-1]
QI1162.Repeat =0
QR1162.QuestID =1162
QR1162.EXP =20000
QR1162.SkillPoint =3

# 1163
QI1163.QuestID =1163
QI1163.QuestSort =1
QI1163.MinLevel =76
QI1163.MaxLevel =90
QI1163.RequiredFaction =1
QI1163.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1163.Color =0
QI1163.Creature =[1073,-1,-1,-1]
QI1163.CreatureCount =[150,-1,-1,-1]
QI1163.Repeat =0
QR1163.QuestID =1163
QR1163.EXP =25000
QR1163.SkillPoint =3

# 1164
QI1164.QuestID =1164
QI1164.QuestSort =1
QI1164.MinLevel =80
QI1164.MaxLevel =96
QI1164.RequiredFaction =1
QI1164.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1164.Color =0
QI1164.Creature =[1074,-1,-1,-1]
QI1164.CreatureCount =[150,-1,-1,-1]
QI1164.Repeat =0
QR1164.QuestID =1164
QR1164.EXP =28000
QR1164.SkillPoint =3

# 1165
QI1165.QuestID =1165
QI1165.QuestSort =1
QI1165.MinLevel =86
QI1165.MaxLevel =100
QI1165.RequiredFaction =1
QI1165.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1165.Color =0
QI1165.Creature =[1090,-1,-1,-1]
QI1165.CreatureCount =[170,-1,-1,-1]
QI1165.Repeat =0
QR1165.QuestID =1165
QR1165.EXP =32000
QR1165.SkillPoint =5

# 1166
QI1166.QuestID =1166
QI1166.QuestSort =1
QI1166.MinLevel =90
QI1166.MaxLevel =110
QI1166.RequiredFaction =1
QI1166.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1166.Color =0
QI1166.Creature =[1092,-1,-1,-1]
QI1166.CreatureCount =[180,-1,-1,-1]
QI1166.Repeat =0
QR1166.QuestID =1166
QR1166.EXP =38000
QR1166.SkillPoint =5

# 1167
QI1167.QuestID =1167
QI1167.QuestSort =5
QI1167.MinLevel =94
QI1167.MaxLevel =112
QI1167.RequiredFaction =1
QI1167.MinTime =[0,1,0,-1]
QI1167.MaxTime =[23,58,0,-1]
QI1167.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1167.Color =0
QI1167.Creature =[1101,-1,-1,-1]
QI1167.CreatureCount =[100,-1,-1,-1]
QI1167.Repeat =3
QI1167.RewardItem[0].Base =4231
QI1167.RewardItem[0].Overlap =1
QI1167.RewardItem[0].Binding =1
QR1167.QuestID =1167
QR1167.EXP =40000
QR1167.SkillPoint =6

# 1168
QI1168.QuestID =1168
QI1168.QuestSort =5
QI1168.MinLevel =100
QI1168.MaxLevel =116
QI1168.RequiredFaction =1
QI1168.MinTime =[0,1,0,-1]
QI1168.MaxTime =[23,58,0,-1]
QI1168.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1168.Color =0
QI1168.Creature =[1104,-1,-1,-1]
QI1168.CreatureCount =[100,-1,-1,-1]
QI1168.Repeat =3
QI1168.RewardItem[0].Base =4221
QI1168.RewardItem[0].Overlap =1
QI1168.RewardItem[0].Binding =1
QR1168.QuestID =1168
QR1168.EXP =45000
QR1168.SkillPoint =6

# 1169
QI1169.QuestID =1169
QI1169.QuestSort =5
QI1169.MinLevel =106
QI1169.MaxLevel =120
QI1169.RequiredFaction =1
QI1169.MinTime =[0,1,0,-1]
QI1169.MaxTime =[23,58,0,-1]
QI1169.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1169.Color =1
QI1169.Creature =[1117,-1,-1,-1]
QI1169.CreatureCount =[100,-1,-1,-1]
QI1169.Repeat =3
QI1169.RewardItem[0].Base =4211
QI1169.RewardItem[0].Overlap =1
QI1169.RewardItem[0].Binding =1
QR1169.QuestID =1169
QR1169.EXP =55000
QR1169.SkillPoint =8

# 1170
QI1170.QuestID =1170
QI1170.QuestSort =5
QI1170.MinLevel =110
QI1170.MaxLevel =120
QI1170.RequiredFaction =1
QI1170.MinTime =[0,1,0,-1]
QI1170.MaxTime =[23,58,0,-1]
QI1170.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1170.Color =2
QI1170.Creature =[1085,-1,-1,-1]
QI1170.CreatureCount =[200,-1,-1,-1]
QI1170.Repeat =3
QI1170.RewardItem[0].Base =4200
QI1170.RewardItem[0].Overlap =1
QI1170.RewardItem[0].Binding =1
QR1170.QuestID =1170
QR1170.EXP =100000
QR1170.SkillPoint =16

# 1171
QI1171.QuestID =1171
QI1171.QuestSort =4
QI1171.MinLevel =50
QI1171.RequiredFaction =1
QI1171.MinTime =[0,1,0,-1]
QI1171.MaxTime =[23,58,0,-1]
QI1171.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1171.Color =1
QI1171.Repeat =1
QI1171.RewardItem[0].Base =4230
QI1171.RewardItem[0].Overlap =1
QI1171.RewardItem[0].Binding =1
QR1171.QuestID =1171
QR1171.EXP =25000
QR1171.SkillPoint =5

# 1172
QI1172.QuestID =1172
QI1172.QuestSort =5
QI1172.MinLevel =48
QI1172.MaxLevel =70
QI1172.RequiredFaction =1
QI1172.MinTime =[0,1,0,-1]
QI1172.MaxTime =[23,58,0,-1]
QI1172.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1172.Color =1
QI1172.Creature =[1110,-1,-1,-1]
QI1172.CreatureCount =[30,-1,-1,-1]
QI1172.Repeat =3
QR1172.QuestID =1172
QR1172.EXP =18000

# 1173
QI1173.QuestID =1173
QI1173.QuestSort =5
QI1173.MinLevel =64
QI1173.MaxLevel =80
QI1173.RequiredFaction =1
QI1173.MinTime =[0,1,0,-1]
QI1173.MaxTime =[23,58,0,-1]
QI1173.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1173.Color =1
QI1173.Creature =[1111,-1,-1,-1]
QI1173.CreatureCount =[40,-1,-1,-1]
QI1173.Repeat =3
QR1173.QuestID =1173
QR1173.EXP =30000

# 1174
QI1174.QuestID =1174
QI1174.QuestSort =5
QI1174.MinLevel =74
QI1174.MaxLevel =92
QI1174.RequiredFaction =1
QI1174.MinTime =[0,1,0,-1]
QI1174.MaxTime =[23,58,0,-1]
QI1174.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1174.Color =1
QI1174.Creature =[1112,-1,-1,-1]
QI1174.CreatureCount =[50,-1,-1,-1]
QI1174.Repeat =3
QR1174.QuestID =1174
QR1174.EXP =46000

# 1175
QI1175.QuestID =1175
QI1175.QuestSort =5
QI1175.MinLevel =82
QI1175.MaxLevel =100
QI1175.RequiredFaction =1
QI1175.MinTime =[0,1,0,-1]
QI1175.MaxTime =[23,58,0,-1]
QI1175.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1175.Color =2
QI1175.Creature =[1113,-1,-1,-1]
QI1175.CreatureCount =[50,-1,-1,-1]
QI1175.Repeat =3
QR1175.QuestID =1175
QR1175.EXP =57000

# 1176
QI1176.QuestID =1176
QI1176.QuestSort =5
QI1176.MinLevel =88
QI1176.MaxLevel =108
QI1176.RequiredFaction =1
QI1176.MinTime =[0,1,0,-1]
QI1176.MaxTime =[23,58,0,-1]
QI1176.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1176.Color =2
QI1176.Creature =[1114,-1,-1,-1]
QI1176.CreatureCount =[50,-1,-1,-1]
QI1176.Repeat =3
QR1176.QuestID =1176
QR1176.EXP =68000

# 1177
QI1177.QuestID =1177
QI1177.QuestSort =5
QI1177.MinLevel =96
QI1177.MaxLevel =118
QI1177.RequiredFaction =1
QI1177.MinTime =[0,1,0,-1]
QI1177.MaxTime =[23,58,0,-1]
QI1177.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1177.Color =2
QI1177.Creature =[1116,-1,-1,-1]
QI1177.CreatureCount =[50,-1,-1,-1]
QI1177.Repeat =3
QR1177.QuestID =1177
QR1177.EXP =80000

# 1178
QI1178.QuestID =1178
QI1178.QuestSort =5
QI1178.MinLevel =104
QI1178.MaxLevel =120
QI1178.RequiredFaction =1
QI1178.MinTime =[0,1,0,-1]
QI1178.MaxTime =[23,58,0,-1]
QI1178.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1178.Color =3
QI1178.Creature =[1119,-1,-1,-1]
QI1178.CreatureCount =[10,-1,-1,-1]
QI1178.Repeat =3
QI1178.RewardItem[0].Base =4230
QI1178.RewardItem[0].Overlap =3
QI1178.RewardItem[0].Binding =1
QI1178.RewardItem[1].Base =4220
QI1178.RewardItem[1].Overlap =2
QI1178.RewardItem[1].Binding =1
QI1178.RewardItem[2].Base =4210
QI1178.RewardItem[2].Overlap =2
QI1178.RewardItem[2].Binding =1
QR1178.QuestID =1178
QR1178.EXP =120000

# 1179
QI1179.QuestID =1179
QI1179.QuestSort =4
QI1179.MinLevel =90
QI1179.MaxLevel =110
QI1179.RequiredFaction =1
QI1179.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1179.Color =1
QI1179.Creature =[1087,-1,-1,-1]
QI1179.CreatureCount =[50,-1,-1,-1]
QI1179.Repeat =0
QR1179.QuestID =1179
QR1179.EXP =40000
QR1179.SkillPoint =6

# 1180
QI1180.QuestID =1180
QI1180.QuestSort =4
QI1180.MinLevel =100
QI1180.MaxLevel =120
QI1180.RequiredFaction =1
QI1180.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1180.Color =1
QI1180.Creature =[1088,-1,-1,-1]
QI1180.CreatureCount =[50,-1,-1,-1]
QI1180.Repeat =0
QR1180.QuestID =1180
QR1180.EXP =55000
QR1180.SkillPoint =8

# 1181
QI1181.QuestID =1181
QI1181.QuestSort =1
QI1181.MinLevel =38
QI1181.MaxLevel =48
QI1181.RequiredFaction =1
QI1181.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1181.Color =0
QI1181.Creature =[1033,-1,-1,-1]
QI1181.CreatureCount =[50,-1,-1,-1]
QI1181.Repeat =0
QR1181.QuestID =1181
QR1181.EXP =4500
QR1181.SkillPoint =1

# 1182
QI1182.QuestID =1182
QI1182.QuestSort =1
QI1182.MinLevel =60
QI1182.MaxLevel =76
QI1182.RequiredFaction =1
QI1182.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1182.Color =0
QI1182.Creature =[1057,-1,-1,-1]
QI1182.CreatureCount =[120,-1,-1,-1]
QI1182.Repeat =0
QR1182.QuestID =1182
QR1182.EXP =17000
QR1182.SkillPoint =3

# 1183
QI1183.QuestID =1183
QI1183.QuestSort =6
QI1183.PrevQuestId =-1
QI1183.NextQuestId =1184
QI1183.MinLevel =3
QI1183.RequiredFaction =1
QI1183.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI1183.Color =1
QI1183.Repeat =3
QR1183.QuestID =1183
QR1183.EXP =100

# 1184
QI1184.QuestID =1184
QI1184.QuestSort =6
QI1184.PrevQuestId =1183
QI1184.NextQuestId =1185
QI1184.MinLevel =3
QI1184.RequiredFaction =1
QI1184.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI1184.Color =1
QI1184.Repeat =3
QR1184.QuestID =1184
QR1184.EXP =100

# 1185
QI1185.QuestID =1185
QI1185.QuestSort =6
QI1185.PrevQuestId =1184
QI1185.NextQuestId =1183
QI1185.MinLevel =3
QI1185.RequiredFaction =1
QI1185.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI1185.Color =1
QI1185.Creature =[1010,-1,-1,-1]
QI1185.CreatureCount =[1,-1,-1,-1]
QI1185.Repeat =3
QI1185.RewardMoney =100
QR1185.QuestID =1185
QR1185.EXP =1000

# 1186
QI1186.QuestID =1186
QI1186.QuestSort =7
QI1186.MinLevel =3
QI1186.RequiredFaction =1
QI1186.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1186.Color =1
QI1186.Repeat =1
QR1186.QuestID =1186
QR1186.EXP =100

# 1187
QI1187.QuestID =1187
QI1187.QuestSort =7
QI1187.MinLevel =3
QI1187.RequiredFaction =1
QI1187.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1187.Color =1
QI1187.Creature =[1013,-1,-1,-1]
QI1187.CreatureCount =[1,-1,-1,-1]
QI1187.Repeat =1
QI1187.RewardMoney =100
QR1187.QuestID =1187
QR1187.EXP =1000

# 1207
QI1207.QuestID =1207
QI1207.QuestSort =8
QI1207.MinLevel =3
QI1207.MaxLevel =17
QI1207.RequiredFaction =1
QI1207.MinTime =[0,1,0,-1]
QI1207.MaxTime =[23,58,0,-1]
QI1207.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1207.Color =0
QI1207.Repeat =3
QI1207.RewardUionMoney =5
QR1207.QuestID =1207
QR1207.EXP =0
QR1207.UionContribute =1

# 1208
QI1208.QuestID =1208
QI1208.QuestSort =8
QI1208.MinLevel =18
QI1208.MaxLevel =32
QI1208.RequiredFaction =1
QI1208.MinTime =[0,1,0,-1]
QI1208.MaxTime =[23,58,0,-1]
QI1208.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1208.Color =0
QI1208.Repeat =3
QI1208.RewardUionMoney =5
QR1208.QuestID =1208
QR1208.EXP =0
QR1208.UionContribute =1

# 1209
QI1209.QuestID =1209
QI1209.QuestSort =8
QI1209.MinLevel =33
QI1209.MaxLevel =47
QI1209.RequiredFaction =1
QI1209.MinTime =[0,1,0,-1]
QI1209.MaxTime =[23,58,0,-1]
QI1209.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1209.Color =0
QI1209.Repeat =3
QI1209.RewardUionMoney =5
QR1209.QuestID =1209
QR1209.EXP =0
QR1209.UionContribute =1

# 1223
QI1223.QuestID =1223
QI1223.QuestSort =8
QI1223.MinLevel =48
QI1223.MaxLevel =62
QI1223.RequiredFaction =1
QI1223.MinTime =[0,1,0,-1]
QI1223.MaxTime =[23,58,0,-1]
QI1223.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1223.Color =0
QI1223.Repeat =3
QI1223.RewardUionMoney =6
QR1223.QuestID =1223
QR1223.EXP =0
QR1223.UionContribute =1

# 1224
QI1224.QuestID =1224
QI1224.QuestSort =8
QI1224.MinLevel =63
QI1224.MaxLevel =77
QI1224.RequiredFaction =1
QI1224.MinTime =[0,1,0,-1]
QI1224.MaxTime =[23,58,0,-1]
QI1224.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1224.Color =0
QI1224.Repeat =3
QI1224.RewardUionMoney =6
QR1224.QuestID =1224
QR1224.EXP =0
QR1224.UionContribute =1

# 1225
QI1225.QuestID =1225
QI1225.QuestSort =8
QI1225.MinLevel =78
QI1225.MaxLevel =92
QI1225.RequiredFaction =1
QI1225.MinTime =[0,1,0,-1]
QI1225.MaxTime =[23,58,0,-1]
QI1225.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1225.Color =0
QI1225.Repeat =3
QI1225.RewardUionMoney =6
QR1225.QuestID =1225
QR1225.EXP =0
QR1225.UionContribute =1

# 1226
QI1226.QuestID =1226
QI1226.QuestSort =8
QI1226.MinLevel =93
QI1226.MaxLevel =107
QI1226.RequiredFaction =1
QI1226.MinTime =[0,1,0,-1]
QI1226.MaxTime =[23,58,0,-1]
QI1226.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI1226.Color =0
QI1226.Repeat =3
QI1226.RewardUionMoney =6
QR1226.QuestID =1226
QR1226.EXP =0
QR1226.UionContribute =2

# 1210
QI1210.QuestID =1210
QI1210.QuestSort =8
QI1210.MinLevel =14
QI1210.MaxLevel =28
QI1210.RequiredFaction =1
QI1210.MinTime =[0,1,0,-1]
QI1210.MaxTime =[23,58,0,-1]
QI1210.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1210.Color =0
QI1210.Creature =[1016,-1,-1,-1]
QI1210.CreatureCount =[100,-1,-1,-1]
QI1210.Repeat =3
QI1210.RewardUionBijou =1
QI1210.RewardUionMoney =10
QR1210.QuestID =1210
QR1210.EXP =0
QR1210.UionContribute =2

# 1211
QI1211.QuestID =1211
QI1211.QuestSort =8
QI1211.MinLevel =29
QI1211.MaxLevel =43
QI1211.RequiredFaction =1
QI1211.MinTime =[0,1,0,-1]
QI1211.MaxTime =[23,58,0,-1]
QI1211.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1211.Color =0
QI1211.Creature =[1032,-1,-1,-1]
QI1211.CreatureCount =[100,-1,-1,-1]
QI1211.Repeat =3
QI1211.RewardUionBijou =1
QI1211.RewardUionMoney =12
QR1211.QuestID =1211
QR1211.EXP =0
QR1211.UionContribute =2

# 1212
QI1212.QuestID =1212
QI1212.QuestSort =8
QI1212.MinLevel =44
QI1212.MaxLevel =58
QI1212.RequiredFaction =1
QI1212.MinTime =[0,1,0,-1]
QI1212.MaxTime =[23,58,0,-1]
QI1212.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1212.Color =0
QI1212.Creature =[1038,-1,-1,-1]
QI1212.CreatureCount =[100,-1,-1,-1]
QI1212.Repeat =3
QI1212.RewardUionBijou =1
QI1212.RewardUionMoney =15
QR1212.QuestID =1212
QR1212.EXP =0
QR1212.UionContribute =2

# 1227
QI1227.QuestID =1227
QI1227.QuestSort =8
QI1227.MinLevel =59
QI1227.MaxLevel =73
QI1227.RequiredFaction =1
QI1227.MinTime =[0,1,0,-1]
QI1227.MaxTime =[23,58,0,-1]
QI1227.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1227.Color =0
QI1227.Creature =[1056,-1,-1,-1]
QI1227.CreatureCount =[100,-1,-1,-1]
QI1227.Repeat =3
QI1227.RewardUionBijou =1
QI1227.RewardUionMoney =19
QR1227.QuestID =1227
QR1227.EXP =0
QR1227.UionContribute =3

# 1228
QI1228.QuestID =1228
QI1228.QuestSort =8
QI1228.MinLevel =74
QI1228.MaxLevel =88
QI1228.RequiredFaction =1
QI1228.MinTime =[0,1,0,-1]
QI1228.MaxTime =[23,58,0,-1]
QI1228.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1228.Color =0
QI1228.Creature =[1072,-1,-1,-1]
QI1228.CreatureCount =[100,-1,-1,-1]
QI1228.Repeat =3
QI1228.RewardUionBijou =1
QI1228.RewardUionMoney =24
QR1228.QuestID =1228
QR1228.EXP =0
QR1228.UionContribute =3

# 1229
QI1229.QuestID =1229
QI1229.QuestSort =8
QI1229.MinLevel =89
QI1229.MaxLevel =103
QI1229.RequiredFaction =1
QI1229.MinTime =[0,1,0,-1]
QI1229.MaxTime =[23,58,0,-1]
QI1229.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1229.Color =0
QI1229.Creature =[1091,-1,-1,-1]
QI1229.CreatureCount =[100,-1,-1,-1]
QI1229.Repeat =3
QI1229.RewardUionBijou =1
QI1229.RewardUionMoney =30
QR1229.QuestID =1229
QR1229.EXP =0
QR1229.UionContribute =3

# 1230
QI1230.QuestID =1230
QI1230.QuestSort =8
QI1230.MinLevel =104
QI1230.MaxLevel =118
QI1230.RequiredFaction =1
QI1230.MinTime =[0,1,0,-1]
QI1230.MaxTime =[23,58,0,-1]
QI1230.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI1230.Color =0
QI1230.Creature =[1096,-1,-1,-1]
QI1230.CreatureCount =[100,-1,-1,-1]
QI1230.Repeat =3
QI1230.RewardUionBijou =1
QI1230.RewardUionMoney =36
QR1230.QuestID =1230
QR1230.EXP =0
QR1230.UionContribute =3

# 1188
QI1188.QuestID =1188
QI1188.QuestSort =4
QI1188.MinLevel =200
QI1188.RequiredFaction =1
QI1188.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1188.Color =0
QI1188.ExplorerMapID =2
QI1188.ExplorerMapPosition =41,27
QI1188.RewardMoney =200
QR1188.QuestID =1188
QR1188.EXP =200

# 1189
QI1189.QuestID =1189
QI1189.QuestSort =4
QI1189.MinLevel =200
QI1189.RequiredFaction =1
QI1189.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1189.Color =0
QI1189.ExplorerMapID =1,1
QI1189.ExplorerMapPosition =28,20,138,-67
QI1189.RewardMoney =500
QR1189.QuestID =1189
QR1189.EXP =500

# 1190
QI1190.QuestID =1190
QI1190.QuestSort =1
QI1190.MinLevel =15
QI1190.MaxLevel =27
QI1190.RequiredFaction =1
QI1190.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1190.Color =0
QI1190.Creature =[1016,-1,-1,-1]
QI1190.CreatureCount =[20,-1,-1,-1]
QI1190.Repeat =0
QR1190.QuestID =1190
QR1190.EXP =800

# 1191
QI1191.QuestID =1191
QI1191.QuestSort =1
QI1191.MinLevel =20
QI1191.MaxLevel =32
QI1191.RequiredFaction =1
QI1191.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1191.Color =0
QI1191.Creature =[1018,-1,-1,-1]
QI1191.CreatureCount =[25,-1,-1,-1]
QI1191.Repeat =0
QR1191.QuestID =1191
QR1191.EXP =1600

# 1197
QI1197.QuestID =1197
QI1197.QuestSort =1
QI1197.MinLevel =25
QI1197.MaxLevel =37
QI1197.RequiredFaction =1
QI1197.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1197.Color =0
QI1197.Creature =[1020,-1,-1,-1]
QI1197.CreatureCount =[30,-1,-1,-1]
QI1197.Repeat =0
QR1197.QuestID =1197
QR1197.EXP =2200
QR1197.SkillPoint =1

# 1198
QI1198.QuestID =1198
QI1198.QuestSort =1
QI1198.MinLevel =30
QI1198.MaxLevel =42
QI1198.RequiredFaction =1
QI1198.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1198.Color =0
QI1198.Creature =[1032,-1,-1,-1]
QI1198.CreatureCount =[35,-1,-1,-1]
QI1198.Repeat =0
QR1198.QuestID =1198
QR1198.EXP =2900
QR1198.SkillPoint =1

# 1199
QI1199.QuestID =1199
QI1199.QuestSort =1
QI1199.MinLevel =40
QI1199.MaxLevel =52
QI1199.RequiredFaction =1
QI1199.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1199.Color =0
QI1199.Creature =[1035,-1,-1,-1]
QI1199.CreatureCount =[40,-1,-1,-1]
QI1199.Repeat =0
QR1199.QuestID =1199
QR1199.EXP =4000
QR1199.SkillPoint =1

# 1192
QI1192.QuestID =1192
QI1192.QuestSort =4
QI1192.MinLevel =12
QI1192.MaxLevel =20
QI1192.RequiredFaction =1
QI1192.TeamLimit =1
QI1192.MinTime =[0,1,0,-1]
QI1192.MaxTime =[23,58,0,-1]
QI1192.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1192.Color =1
QI1192.Creature =[1014,-1,-1,-1]
QI1192.CreatureCount =[50,-1,-1,-1]
QI1192.Repeat =1
QR1192.QuestID =1192
QR1192.EXP =5000
QR1192.SkillPoint =4

# 1193
QI1193.QuestID =1193
QI1193.QuestSort =4
QI1193.MinLevel =21
QI1193.MaxLevel =28
QI1193.RequiredFaction =1
QI1193.TeamLimit =2
QI1193.MinTime =[0,1,0,-1]
QI1193.MaxTime =[23,58,0,-1]
QI1193.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1193.Color =2
QI1193.Creature =[1017,-1,-1,-1]
QI1193.CreatureCount =[1,-1,-1,-1]
QI1193.Repeat =1
QR1193.QuestID =1193
QR1193.EXP =15000
QR1193.SkillPoint =6

# 1194
QI1194.QuestID =1194
QI1194.QuestSort =4
QI1194.MinLevel =30
QI1194.MaxLevel =40
QI1194.RequiredFaction =1
QI1194.TeamLimit =3
QI1194.MinTime =[0,1,0,-1]
QI1194.MaxTime =[23,58,0,-1]
QI1194.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1194.Color =2
QI1194.Creature =[1020,-1,-1,-1]
QI1194.CreatureCount =[100,-1,-1,-1]
QI1194.Repeat =1
QR1194.QuestID =1194
QR1194.EXP =15000
QR1194.SkillPoint =6

# 1195
QI1195.QuestID =1195
QI1195.QuestSort =4
QI1195.MinLevel =20
QI1195.MaxLevel =50
QI1195.RequiredFaction =1
QI1195.TeamLimit =1
QI1195.MinTime =[0,1,0,-1]
QI1195.MaxTime =[23,58,0,-1]
QI1195.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI1195.Color =0
QI1195.Repeat =1
QR1195.QuestID =1195
QR1195.EXP =1000

# 1196
QI1196.QuestID =1196
QI1196.QuestSort =4

# 1200
QI1200.QuestID =1200
QI1200.QuestSort =1
QI1200.MinLevel =50
QI1200.MaxLevel =62
QI1200.RequiredFaction =1
QI1200.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1200.Color =0
QI1200.Creature =[1052,-1,-1,-1]
QI1200.CreatureCount =[50,-1,-1,-1]
QI1200.Repeat =0
QR1200.QuestID =1200
QR1200.EXP =6000
QR1200.SkillPoint =1

# 1201
QI1201.QuestID =1201
QI1201.QuestSort =1
QI1201.MinLevel =60
QI1201.MaxLevel =72
QI1201.RequiredFaction =1
QI1201.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1201.Color =0
QI1201.Creature =[1056,-1,-1,-1]
QI1201.CreatureCount =[60,-1,-1,-1]
QI1201.Repeat =0
QR1201.QuestID =1201
QR1201.EXP =8200
QR1201.SkillPoint =1

# 1202
QI1202.QuestID =1202
QI1202.QuestSort =1
QI1202.MinLevel =70
QI1202.MaxLevel =80
QI1202.RequiredFaction =1
QI1202.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1202.Color =0
QI1202.Creature =[1071,-1,-1,-1]
QI1202.CreatureCount =[70,-1,-1,-1]
QI1202.Repeat =0
QR1202.QuestID =1202
QR1202.EXP =11000
QR1202.SkillPoint =1

# 1203
QI1203.QuestID =1203
QI1203.QuestSort =1
QI1203.MinLevel =81
QI1203.MaxLevel =90
QI1203.RequiredFaction =1
QI1203.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1203.Color =0
QI1203.Creature =[1074,-1,-1,-1]
QI1203.CreatureCount =[80,-1,-1,-1]
QI1203.Repeat =0
QR1203.QuestID =1203
QR1203.EXP =14000
QR1203.SkillPoint =2

# 1204
QI1204.QuestID =1204
QI1204.QuestSort =1
QI1204.MinLevel =91
QI1204.MaxLevel =100
QI1204.RequiredFaction =1
QI1204.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1204.Color =0
QI1204.Creature =[1116,-1,-1,-1]
QI1204.CreatureCount =[90,-1,-1,-1]
QI1204.Repeat =0
QR1204.QuestID =1204
QR1204.EXP =18000
QR1204.SkillPoint =2

# 1205
QI1205.QuestID =1205
QI1205.QuestSort =1
QI1205.MinLevel =101
QI1205.MaxLevel =111
QI1205.RequiredFaction =1
QI1205.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1205.Color =0
QI1205.Creature =[1118,-1,-1,-1]
QI1205.CreatureCount =[100,-1,-1,-1]
QI1205.Repeat =0
QR1205.QuestID =1205
QR1205.EXP =28000
QR1205.SkillPoint =4

# 1206
QI1206.QuestID =1206
QI1206.QuestSort =1
QI1206.MinLevel =111
QI1206.MaxLevel =119
QI1206.RequiredFaction =1
QI1206.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI1206.Color =0
QI1206.Creature =[1096,-1,-1,-1]
QI1206.CreatureCount =[100,-1,-1,-1]
QI1206.Repeat =0
QR1206.QuestID =1206
QR1206.EXP =32000
QR1206.SkillPoint =4

# 1213
QI1213.QuestID =1213
QI1213.QuestSort =4
QI1213.MinLevel =200
QI1213.RequiredFaction =1
QI1213.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1213.Color =0
QI1213.ExplorerMapID =1
QI1213.ExplorerMapPosition =-95,99
QI1213.RewardMoney =1000
QR1213.QuestID =1213
QR1213.EXP =2000

# 1214
QI1214.QuestID =1214
QI1214.QuestSort =4
QI1214.MinLevel =200
QI1214.RequiredFaction =1
QI1214.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1214.Color =0
QI1214.ExplorerMapID =1
QI1214.ExplorerMapPosition =-84,-92
QI1214.RewardMoney =2000
QR1214.QuestID =1214
QR1214.EXP =4000

# 1215
QI1215.QuestID =1215
QI1215.QuestSort =4
QI1215.MinLevel =200
QI1215.RequiredFaction =1
QI1215.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1215.Color =0
QI1215.ExplorerMapID =11
QI1215.ExplorerMapPosition =-114,-174
QI1215.RewardMoney =2700
QR1215.QuestID =1215
QR1215.EXP =5400

# 1216
QI1216.QuestID =1216
QI1216.QuestSort =4
QI1216.MinLevel =200
QI1216.RequiredFaction =1
QI1216.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1216.Color =0
QI1216.ExplorerMapID =3
QI1216.ExplorerMapPosition =-12,67
QI1216.RewardMoney =3200
QR1216.QuestID =1216
QR1216.EXP =6400

# 1217
QI1217.QuestID =1217
QI1217.QuestSort =2
QI1217.NextQuestsId =1218,-1
QI1217.MinLevel =70
QI1217.RequiredFaction =1
QI1217.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1217.Color =1
QI1217.Creature =[8061,-1,-1,-1]
QI1217.CreatureCount =[1,-1,-1,-1]
QI1217.Repeat =1
QI1217.RewardMoney =20000
QR1217.QuestID =1217
QR1217.EXP =10000
QR1217.SkillPoint =1

# 1218
QI1218.QuestID =1218
QI1218.QuestSort =2
QI1218.PrevQuestId =1217
QI1218.NextQuestsId =1219,-1
QI1218.MinLevel =70
QI1218.RequiredFaction =1
QI1218.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1218.Color =1
QI1218.Repeat =1
QI1218.RewardMoney =1000
QR1218.QuestID =1218
QR1218.EXP =3000

# 1219
QI1219.QuestID =1219
QI1219.QuestSort =4
QI1219.PrevQuestId =1218
QI1219.NextQuestsId =1220,-1
QI1219.MinLevel =200
QI1219.RequiredFaction =1
QI1219.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI1219.Color =1
QI1219.ExplorerMapID =19
QI1219.ExplorerMapPosition =131,146
QI1219.RewardMoney =2000
QR1219.QuestID =1219
QR1219.EXP =5000

# 1220
QI1220.QuestID =1220
QI1220.QuestSort =2
QI1220.PrevQuestId =1219
QI1220.NextQuestsId =1221,-1
QI1220.MinLevel =75
QI1220.RequiredFaction =1
QI1220.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1220.Color =1
QI1220.Creature =[8062,-1,-1,-1]
QI1220.CreatureCount =[1,-1,-1,-1]
QI1220.Repeat =1
QI1220.RewardMoney =20000
QR1220.QuestID =1220
QR1220.EXP =12000
QR1220.SkillPoint =2

# 1221
QI1221.QuestID =1221
QI1221.QuestSort =2
QI1221.PrevQuestId =1220
QI1221.NextQuestsId =1222,-1
QI1221.MinLevel =90
QI1221.RequiredFaction =1
QI1221.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI1221.Color =1
QI1221.Creature =[1076,-1,-1,-1]
QI1221.CreatureCount =[1,-1,-1,-1]
QI1221.Repeat =1
QI1221.RewardMoney =30000
QR1221.QuestID =1221
QR1221.EXP =40000
QR1221.SkillPoint =3

# 1222
QI1222.QuestID =1222
QI1222.QuestSort =2
QI1222.PrevQuestId =1221
QI1222.MinLevel =90
QI1222.RequiredFaction =1
QI1222.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1222.Color =1
QI1222.Repeat =1
QI1222.RewardMoney =0
QR1222.QuestID =1222
QR1222.EXP =10000
QR1222.SkillPoint =1

# 0
QI0.QuestID =0
QI0.QuestSort =0
QI0.NextQuestId =1
QI0.MinLevel =1
QI0.RequiredFaction =0
QI0.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI0.Color =0
QI0.Repeat =1
QI0.RewardItem[0].Base =2900
QI0.RewardItem[0].Append =[50,-1,-1,-1,-1]
QI0.RewardItem[0].BaseLv =1
QI0.RewardItem[0].AppendLv =1
QI0.RewardItem[0].Overlap =1
QI0.RewardItem[0].Binding =1
QI0.RewardItem[1].Base =2900
QI0.RewardItem[1].Append =[130,-1,-1,-1,-1]
QI0.RewardItem[1].BaseLv =1
QI0.RewardItem[1].AppendLv =1
QI0.RewardItem[1].Overlap =1
QI0.RewardItem[1].Binding =1
QI0.RewardItem[2].Base =2900
QI0.RewardItem[2].Append =[150,-1,-1,-1,-1]
QI0.RewardItem[2].BaseLv =1
QI0.RewardItem[2].AppendLv =1
QI0.RewardItem[2].Overlap =1
QI0.RewardItem[2].Binding =1
QR0.QuestID =0
QR0.EXP =100

# 1
QI1.QuestID =1
QI1.QuestSort =0
QI1.PrevQuestId =0
QI1.NextQuestId =2
QI1.MinLevel =1
QI1.RequiredFaction =0
QI1.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI1.Color =0
QI1.Repeat =1
QI1.RewardItem[0].Base =4000
QI1.RewardItem[0].Overlap =10
QI1.RewardItem[0].Binding =0
QR1.QuestID =1
QR1.EXP =100

# 2
QI2.QuestID =2
QI2.QuestSort =0
QI2.PrevQuestId =1
QI2.NextQuestId =3
QI2.MinLevel =1
QI2.RequiredFaction =0
QI2.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI2.Color =0
QI2.Repeat =1
QI2.RewardItem[0].Base =4030
QI2.RewardItem[0].Overlap =10
QI2.RewardItem[0].Binding =0
QR2.QuestID =2
QR2.EXP =150

# 3
QI3.QuestID =3
QI3.QuestSort =0
QI3.PrevQuestId =2
QI3.NextQuestId =4
QI3.MinLevel =1
QI3.RequiredFaction =0
QI3.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI3.Color =0
QI3.Repeat =1
QI3.RewardItem[0].Base =2800
QI3.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI3.RewardItem[0].BaseLv =1
QI3.RewardItem[0].AppendLv =1
QI3.RewardItem[0].Overlap =1
QI3.RewardItem[0].Binding =1
QI3.RewardItem[1].Base =2800
QI3.RewardItem[1].Append =[20,-1,-1,-1,-1]
QI3.RewardItem[1].BaseLv =1
QI3.RewardItem[1].AppendLv =1
QI3.RewardItem[1].Overlap =1
QI3.RewardItem[1].Binding =1
QR3.QuestID =3
QR3.EXP =150

# 4
QI4.QuestID =4
QI4.QuestSort =0
QI4.PrevQuestId =3
QI4.NextQuestId =5
QI4.MinLevel =1
QI4.RequiredFaction =0
QI4.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI4.Color =0
QI4.Repeat =1
QI4.RewardMoney =2000
QI4.RewardItem[0].Base =1000
QI4.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI4.RewardItem[0].BaseLv =1
QI4.RewardItem[0].AppendLv =1
QI4.RewardItem[0].Overlap =1
QI4.RewardItem[0].Binding =1
QI4.RewardItem[1].Base =1400
QI4.RewardItem[1].Append =[0,-1,-1,-1,-1]
QI4.RewardItem[1].BaseLv =1
QI4.RewardItem[1].AppendLv =1
QI4.RewardItem[1].Overlap =1
QI4.RewardItem[1].Binding =1
QI4.RewardItem[2].Base =1700
QI4.RewardItem[2].Append =[20,-1,-1,-1,-1]
QI4.RewardItem[2].BaseLv =1
QI4.RewardItem[2].AppendLv =1
QI4.RewardItem[2].Overlap =1
QI4.RewardItem[2].Binding =1
QI4.RewardItem[3].Base =1800
QI4.RewardItem[3].Append =[20,-1,-1,-1,-1]
QI4.RewardItem[3].BaseLv =1
QI4.RewardItem[3].AppendLv =1
QI4.RewardItem[3].Overlap =1
QI4.RewardItem[3].Binding =1
QR4.QuestID =4
QR4.EXP =0
QR4.SkillPoint =1

# 5
QI5.QuestID =5
QI5.QuestSort =0
QI5.PrevQuestId =4
QI5.NextQuestId =6
QI5.MinLevel =1
QI5.RequiredFaction =0
QI5.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI5.Color =0
QI5.Creature =[1027,-1,-1,-1]
QI5.CreatureCount =[20,-1,-1,-1]
QI5.Repeat =1
QI5.RewardItem[0].Base =2100
QI5.RewardItem[0].Append =[100,-1,-1,-1,-1]
QI5.RewardItem[0].BaseLv =1
QI5.RewardItem[0].AppendLv =1
QI5.RewardItem[0].Overlap =1
QI5.RewardItem[0].Binding =1
QI5.RewardItem[1].Base =2200
QI5.RewardItem[1].Append =[100,-1,-1,-1,-1]
QI5.RewardItem[1].BaseLv =1
QI5.RewardItem[1].AppendLv =1
QI5.RewardItem[1].Overlap =1
QI5.RewardItem[1].Binding =1
QR5.QuestID =5
QR5.EXP =500
QR5.SkillPoint =1

# 6
QI6.QuestID =6
QI6.QuestSort =0
QI6.PrevQuestId =5
QI6.NextQuestId =7
QI6.MinLevel =1
QI6.RequiredFaction =0
QI6.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI6.Color =0
QI6.Repeat =1
QR6.QuestID =6
QR6.EXP =150

# 7
QI7.QuestID =7
QI7.QuestSort =0
QI7.PrevQuestId =6
QI7.NextQuestId =8
QI7.MinLevel =1
QI7.RequiredFaction =0
QI7.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI7.Color =0
QI7.Repeat =1
QR7.QuestID =7
QR7.EXP =150

# 8
QI8.QuestID =8
QI8.QuestSort =0
QI8.PrevQuestId =7
QI8.NextQuestId =9
QI8.MinLevel =1
QI8.RequiredFaction =0
QI8.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI8.Color =0
QI8.Creature =[1021,-1,-1,-1]
QI8.CreatureCount =[20,-1,-1,-1]
QI8.Repeat =1
QI8.RewardItem[0].Base =3000
QI8.RewardItem[0].Append =[100,-1,-1,-1,-1]
QI8.RewardItem[0].BaseLv =2
QI8.RewardItem[0].AppendLv =2
QI8.RewardItem[0].Overlap =1
QI8.RewardItem[0].Binding =1
QR8.QuestID =8
QR8.EXP =700
QR8.SkillPoint =1

# 9
QI9.QuestID =9
QI9.QuestSort =0
QI9.PrevQuestId =8
QI9.NextQuestId =10
QI9.MinLevel =1
QI9.RequiredFaction =0
QI9.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI9.Color =0
QI9.Creature =[1028,-1,-1,-1]
QI9.CreatureCount =[20,-1,-1,-1]
QI9.Repeat =1
QR9.QuestID =9
QR9.EXP =800
QR9.SkillPoint =1

# 10
QI10.QuestID =10
QI10.QuestSort =0
QI10.PrevQuestId =9
QI10.NextQuestId =11
QI10.MinLevel =1
QI10.RequiredFaction =0
QI10.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI10.Color =0
QI10.Repeat =1
QI10.RewardItem[0].Base =2300
QI10.RewardItem[0].Append =[80,130,-1,-1,-1]
QI10.RewardItem[0].BaseLv =1
QI10.RewardItem[0].AppendLv =1
QI10.RewardItem[0].Overlap =1
QI10.RewardItem[0].Binding =1
QI10.RewardItem[1].Base =2400
QI10.RewardItem[1].Append =[90,130,-1,-1,-1]
QI10.RewardItem[1].BaseLv =1
QI10.RewardItem[1].AppendLv =1
QI10.RewardItem[1].Overlap =1
QI10.RewardItem[1].Binding =1
QR10.QuestID =10
QR10.EXP =200

# 11
QI11.QuestID =11
QI11.QuestSort =0
QI11.PrevQuestId =10
QI11.NextQuestId =12
QI11.MinLevel =1
QI11.RequiredFaction =0
QI11.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI11.Color =0
QI11.Repeat =1
QI11.RewardItem[0].Base =2600
QI11.RewardItem[0].Append =[10,-1,-1,-1,-1]
QI11.RewardItem[0].BaseLv =1
QI11.RewardItem[0].AppendLv =1
QI11.RewardItem[0].Overlap =1
QI11.RewardItem[0].Binding =1
QI11.RewardItem[1].Base =2600
QI11.RewardItem[1].Append =[40,-1,-1,-1,-1]
QI11.RewardItem[1].BaseLv =1
QI11.RewardItem[1].AppendLv =1
QI11.RewardItem[1].Overlap =1
QI11.RewardItem[1].Binding =1
QI11.RewardItem[2].Base =2600
QI11.RewardItem[2].Append =[150,-1,-1,-1,-1]
QI11.RewardItem[2].BaseLv =1
QI11.RewardItem[2].AppendLv =1
QI11.RewardItem[2].Overlap =1
QI11.RewardItem[2].Binding =1
QR11.QuestID =11
QR11.EXP =200

# 12
QI12.QuestID =12
QI12.QuestSort =0
QI12.PrevQuestId =11
QI12.NextQuestId =13
QI12.MinLevel =10
QI12.RequiredFaction =0
QI12.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI12.Color =0
QI12.Creature =[1023,-1,-1,-1]
QI12.CreatureCount =[20,-1,-1,-1]
QI12.Repeat =1
QI12.RewardItem[0].Base =2700
QI12.RewardItem[0].Append =[10,-1,-1,-1,-1]
QI12.RewardItem[0].BaseLv =1
QI12.RewardItem[0].AppendLv =1
QI12.RewardItem[0].Overlap =1
QI12.RewardItem[0].Binding =1
QI12.RewardItem[1].Base =2700
QI12.RewardItem[1].Append =[50,-1,-1,-1,-1]
QI12.RewardItem[1].BaseLv =1
QI12.RewardItem[1].AppendLv =1
QI12.RewardItem[1].Overlap =1
QI12.RewardItem[1].Binding =1
QI12.RewardItem[2].Base =2700
QI12.RewardItem[2].Append =[120,-1,-1,-1,-1]
QI12.RewardItem[2].BaseLv =1
QI12.RewardItem[2].AppendLv =1
QI12.RewardItem[2].Overlap =1
QI12.RewardItem[2].Binding =1
QI12.RequiredLevel =10
QR12.QuestID =12
QR12.EXP =1000
QR12.SkillPoint =1

# 13
QI13.QuestID =13
QI13.QuestSort =0
QI13.PrevQuestId =12
QI13.NextQuestId =14
QI13.MinLevel =11
QI13.RequiredFaction =0
QI13.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI13.Color =0
QI13.Item =[501,-1,-1,-1]
QI13.ItemCount =[10,-1,-1,-1]
QI13.ItemProbability =[60,-1,-1,-1]
QI13.Repeat =1
QR13.QuestID =13
QR13.EXP =1200
QR13.SkillPoint =2

# 14
QI14.QuestID =14
QI14.QuestSort =0
QI14.PrevQuestId =13
QI14.NextQuestId =15
QI14.MinLevel =12
QI14.RequiredFaction =0
QI14.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI14.Color =0
QI14.Repeat =1
QI14.RewardMoney =3000
QI14.RewardItem[0].Base =4220
QI14.RewardItem[0].Overlap =5
QI14.RewardItem[0].Binding =1
QR14.QuestID =14
QR14.EXP =200

# 15
QI15.QuestID =15
QI15.QuestSort =0
QI15.PrevQuestId =14
QI15.NextQuestId =16
QI15.MinLevel =12
QI15.RequiredFaction =0
QI15.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI15.Color =0
QI15.Repeat =1
QI15.RequiredLevel =12
QR15.QuestID =15
QR15.EXP =500
QR15.SkillPoint =1

# 16
QI16.QuestID =16
QI16.QuestSort =0
QI16.PrevQuestId =15
QI16.NextQuestId =17
QI16.MinLevel =13
QI16.RequiredFaction =0
QI16.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI16.Color =0
QI16.Creature =[1024,-1,-1,-1]
QI16.CreatureCount =[20,-1,-1,-1]
QI16.Repeat =1
QI16.RewardItem[0].Base =3100
QI16.RewardItem[0].Append =[50,-1,-1,-1,-1]
QI16.RewardItem[0].BaseLv =2
QI16.RewardItem[0].AppendLv =1
QI16.RewardItem[0].Overlap =1
QI16.RewardItem[0].Binding =1
QI16.RewardItem[1].Base =3100
QI16.RewardItem[1].Append =[70,-1,-1,-1,-1]
QI16.RewardItem[1].BaseLv =2
QI16.RewardItem[1].AppendLv =1
QI16.RewardItem[1].Overlap =1
QI16.RewardItem[1].Binding =1
QI16.RewardItem[2].Base =3100
QI16.RewardItem[2].Append =[120,-1,-1,-1,-1]
QI16.RewardItem[2].BaseLv =2
QI16.RewardItem[2].AppendLv =1
QI16.RewardItem[2].Overlap =1
QI16.RewardItem[2].Binding =1
QR16.QuestID =16
QR16.EXP =1400
QR16.SkillPoint =2

# 17
QI17.QuestID =17
QI17.QuestSort =0
QI17.PrevQuestId =16
QI17.NextQuestId =18
QI17.MinLevel =13
QI17.RequiredFaction =0
QI17.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI17.Color =0
QI17.Repeat =1
QR17.QuestID =17
QR17.EXP =400

# 18
QI18.QuestID =18
QI18.QuestSort =0
QI18.PrevQuestId =17
QI18.NextQuestId =19
QI18.MinLevel =14
QI18.RequiredFaction =0
QI18.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI18.Color =0
QI18.Repeat =1
QR18.QuestID =18
QR18.EXP =400

# 19
QI19.QuestID =19
QI19.QuestSort =0
QI19.PrevQuestId =18
QI19.NextQuestId =20
QI19.MinLevel =15
QI19.RequiredFaction =0
QI19.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI19.Color =0
QI19.Repeat =1
QI19.RequiredLevel =16
QR19.QuestID =19
QR19.EXP =400

# 20
QI20.QuestID =20
QI20.QuestSort =0
QI20.PrevQuestId =19
QI20.NextQuestId =21
QI20.MinLevel =16
QI20.RequiredFaction =0
QI20.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI20.Color =0
QI20.Creature =[1025,-1,-1,-1]
QI20.CreatureCount =[20,-1,-1,-1]
QI20.Repeat =1
QI20.RewardItem[0].Base =1001
QI20.RewardItem[0].Append =[40,-1,-1,-1,-1]
QI20.RewardItem[0].BaseLv =2
QI20.RewardItem[0].AppendLv =1
QI20.RewardItem[0].Overlap =1
QI20.RewardItem[0].Binding =1
QI20.RewardItem[1].Base =1401
QI20.RewardItem[1].Append =[60,-1,-1,-1,-1]
QI20.RewardItem[1].BaseLv =2
QI20.RewardItem[1].AppendLv =1
QI20.RewardItem[1].Overlap =1
QI20.RewardItem[1].Binding =1
QI20.RewardItem[2].Base =1701
QI20.RewardItem[2].Append =[40,-1,-1,-1,-1]
QI20.RewardItem[2].BaseLv =2
QI20.RewardItem[2].AppendLv =1
QI20.RewardItem[2].Overlap =1
QI20.RewardItem[2].Binding =1
QI20.RewardItem[3].Base =1801
QI20.RewardItem[3].Append =[60,-1,-1,-1,-1]
QI20.RewardItem[3].BaseLv =2
QI20.RewardItem[3].AppendLv =1
QI20.RewardItem[3].Overlap =1
QI20.RewardItem[3].Binding =1
QR20.QuestID =20
QR20.EXP =1600
QR20.SkillPoint =2

# 21
QI21.QuestID =21
QI21.QuestSort =0
QI21.PrevQuestId =20
QI21.NextQuestId =22
QI21.MinLevel =17
QI21.RequiredFaction =0
QI21.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI21.Color =0
QI21.Repeat =1
QR21.QuestID =21
QR21.EXP =400

# 22
QI22.QuestID =22
QI22.QuestSort =0
QI22.PrevQuestId =21
QI22.NextQuestId =23
QI22.MinLevel =18
QI22.RequiredFaction =0
QI22.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI22.Color =0
QI22.Repeat =1
QR22.QuestID =22
QR22.EXP =1000
QR22.SkillPoint =1

# 23
QI23.QuestID =23
QI23.QuestSort =0
QI23.PrevQuestId =22
QI23.NextQuestId =24
QI23.MinLevel =18
QI23.RequiredFaction =0
QI23.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI23.Color =0
QI23.Repeat =1
QR23.QuestID =23
QR23.EXP =500

# 24
QI24.QuestID =24
QI24.QuestSort =0
QI24.PrevQuestId =23
QI24.NextQuestId =25
QI24.MinLevel =19
QI24.RequiredFaction =0
QI24.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI24.Color =0
QI24.Repeat =1
QI24.RequiredLevel =20
QR24.QuestID =24
QR24.EXP =500
QR24.SkillPoint =1

# 25
QI25.QuestID =25
QI25.QuestSort =0
QI25.PrevQuestId =24
QI25.NextQuestId =26
QI25.MinLevel =20
QI25.RequiredFaction =0
QI25.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI25.Color =0
QI25.Item =[502,-1,-1,-1]
QI25.ItemCount =[8,-1,-1,-1]
QI25.ItemProbability =[40,-1,-1,-1]
QI25.Repeat =1
QI25.RewardMoney =4000
QI25.RewardItem[0].Base =4230
QI25.RewardItem[0].Overlap =1
QI25.RewardItem[0].Binding =1
QR25.QuestID =25
QR25.EXP =2000
QR25.SkillPoint =2

# 26
QI26.QuestID =26
QI26.QuestSort =0
QI26.PrevQuestId =25
QI26.NextQuestId =27
QI26.MinLevel =20
QI26.RequiredFaction =0
QI26.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI26.Color =0
QI26.Repeat =1
QR26.QuestID =26
QR26.EXP =500

# 27
QI27.QuestID =27
QI27.QuestSort =0
QI27.PrevQuestId =26
QI27.NextQuestId =28
QI27.MinLevel =21
QI27.RequiredFaction =0
QI27.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI27.Color =0
QI27.Repeat =1
QI27.RewardItem[0].Base =1002
QI27.RewardItem[0].Append =[0,-1,-1,-1,-1]
QI27.RewardItem[0].BaseLv =2
QI27.RewardItem[0].AppendLv =2
QI27.RewardItem[0].Overlap =1
QI27.RewardItem[0].Binding =1
QI27.RewardItem[1].Base =1402
QI27.RewardItem[1].Append =[0,-1,-1,-1,-1]
QI27.RewardItem[1].BaseLv =2
QI27.RewardItem[1].AppendLv =2
QI27.RewardItem[1].Overlap =1
QI27.RewardItem[1].Binding =1
QI27.RewardItem[2].Base =1702
QI27.RewardItem[2].Append =[20,-1,-1,-1,-1]
QI27.RewardItem[2].BaseLv =2
QI27.RewardItem[2].AppendLv =2
QI27.RewardItem[2].Overlap =1
QI27.RewardItem[2].Binding =1
QI27.RewardItem[3].Base =1802
QI27.RewardItem[3].Append =[20,-1,-1,-1,-1]
QI27.RewardItem[3].BaseLv =2
QI27.RewardItem[3].AppendLv =2
QI27.RewardItem[3].Overlap =1
QI27.RewardItem[3].Binding =1
QR27.QuestID =27
QR27.EXP =800

# 28
QI28.QuestID =28
QI28.QuestSort =0
QI28.PrevQuestId =27
QI28.NextQuestId =29
QI28.MinLevel =22
QI28.RequiredFaction =0
QI28.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI28.Color =0
QI28.Repeat =1
QR28.QuestID =28
QR28.EXP =500

# 29
QI29.QuestID =29
QI29.QuestSort =0
QI29.PrevQuestId =28
QI29.NextQuestId =30
QI29.MinLevel =23
QI29.RequiredFaction =0
QI29.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI29.Color =0
QI29.Repeat =1
QR29.QuestID =29
QR29.EXP =500

# 30
QI30.QuestID =30
QI30.QuestSort =0
QI30.PrevQuestId =29
QI30.NextQuestId =31
QI30.MinLevel =23
QI30.RequiredFaction =0
QI30.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI30.Color =0
QI30.Repeat =1
QR30.QuestID =30
QR30.EXP =500

# 31
QI31.QuestID =31
QI31.QuestSort =0
QI31.PrevQuestId =30
QI31.NextQuestId =32
QI31.MinLevel =24
QI31.RequiredFaction =0
QI31.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI31.Color =0
QI31.Repeat =1
QI31.RewardItem[0].Base =4001
QI31.RewardItem[0].Overlap =10
QI31.RewardItem[0].Binding =0
QR31.QuestID =31
QR31.EXP =800

# 32
QI32.QuestID =32
QI32.QuestSort =0
QI32.PrevQuestId =31
QI32.NextQuestId =33
QI32.MinLevel =24
QI32.RequiredFaction =0
QI32.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI32.Color =0
QI32.Item =[503,-1,-1,-1]
QI32.ItemCount =[3,-1,-1,-1]
QI32.ItemProbability =[15,-1,-1,-1]
QI32.Repeat =1
QI32.RewardMoney =5000
QR32.QuestID =32
QR32.EXP =2500
QR32.SkillPoint =1

# 33
QI33.QuestID =33
QI33.QuestSort =0
QI33.PrevQuestId =32
QI33.NextQuestId =34
QI33.MinLevel =24
QI33.RequiredFaction =0
QI33.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI33.Color =0
QI33.Repeat =1
QI33.RewardItem[0].Base =4031
QI33.RewardItem[0].Overlap =10
QI33.RewardItem[0].Binding =0
QR33.QuestID =33
QR33.EXP =600

# 34
QI34.QuestID =34
QI34.QuestSort =0
QI34.PrevQuestId =33
QI34.NextQuestId =35
QI34.MinLevel =25
QI34.RequiredFaction =0
QI34.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI34.Color =0
QI34.Repeat =1
QR34.QuestID =34
QR34.EXP =600

# 35
QI35.QuestID =35
QI35.QuestSort =0
QI35.PrevQuestId =34
QI35.NextQuestId =36
QI35.MinLevel =25
QI35.RequiredFaction =0
QI35.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI35.Color =0
QI35.Repeat =1
QR35.QuestID =35
QR35.EXP =600

# 36
QI36.QuestID =36
QI36.QuestSort =0
QI36.PrevQuestId =35
QI36.NextQuestId =37
QI36.MinLevel =25
QI36.RequiredFaction =0
QI36.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI36.Color =0
QI36.Repeat =1
QR36.QuestID =36
QR36.EXP =600

# 37
QI37.QuestID =37
QI37.QuestSort =0
QI37.PrevQuestId =36
QI37.NextQuestId =38
QI37.MinLevel =26
QI37.RequiredFaction =0
QI37.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI37.Color =0
QI37.Repeat =1
QI37.RewardItem[0].Base =4220
QI37.RewardItem[0].Overlap =2
QI37.RewardItem[0].Binding =1
QR37.QuestID =37
QR37.EXP =600

# 38
QI38.QuestID =38
QI38.QuestSort =0
QI38.PrevQuestId =37
QI38.NextQuestId =39
QI38.MinLevel =26
QI38.RequiredFaction =0
QI38.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI38.Color =0
QI38.Repeat =1
QR38.QuestID =38
QR38.EXP =700

# 39
QI39.QuestID =39
QI39.QuestSort =0
QI39.PrevQuestId =38
QI39.NextQuestId =40
QI39.MinLevel =27
QI39.RequiredFaction =0
QI39.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI39.Color =0
QI39.Repeat =1
QR39.QuestID =39
QR39.EXP =800

# 40
QI40.QuestID =40
QI40.QuestSort =0
QI40.PrevQuestId =39
QI40.NextQuestId =41
QI40.MinLevel =27
QI40.RequiredFaction =0
QI40.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI40.Color =0
QI40.Repeat =1
QI40.RequiredLevel =28
QR40.QuestID =40
QR40.EXP =900

# 41
QI41.QuestID =41
QI41.QuestSort =0
QI41.PrevQuestId =40
QI41.NextQuestId =42
QI41.MinLevel =28
QI41.RequiredFaction =0
QI41.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI41.Color =0
QI41.Item =[504,-1,-1,-1]
QI41.ItemCount =[1,-1,-1,-1]
QI41.ItemProbability =[8,-1,-1,-1]
QI41.Repeat =1
QI41.RewardMoney =2000
QI41.RewardItem[0].Base =4210
QI41.RewardItem[0].Overlap =2
QI41.RewardItem[0].Binding =1
QR41.QuestID =41
QR41.EXP =2500
QR41.SkillPoint =2

# 42
QI42.QuestID =42
QI42.QuestSort =0
QI42.PrevQuestId =41
QI42.NextQuestId =43
QI42.MinLevel =28
QI42.RequiredFaction =0
QI42.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI42.Color =0
QI42.Repeat =1
QR42.QuestID =42
QR42.EXP =700

# 43
QI43.QuestID =43
QI43.QuestSort =0
QI43.PrevQuestId =42
QI43.NextQuestId =44
QI43.MinLevel =28
QI43.RequiredFaction =0
QI43.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI43.Color =0
QI43.Repeat =1
QR43.QuestID =43
QR43.EXP =700

# 44
QI44.QuestID =44
QI44.QuestSort =0
QI44.PrevQuestId =43
QI44.NextQuestId =45
QI44.MinLevel =29
QI44.RequiredFaction =0
QI44.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI44.Color =0
QI44.Repeat =1
QI44.RewardItem[0].Base =2802
QI44.RewardItem[0].Append =[0,40,-1,-1,-1]
QI44.RewardItem[0].BaseLv =2
QI44.RewardItem[0].AppendLv =1
QI44.RewardItem[0].Overlap =1
QI44.RewardItem[0].Binding =1
QI44.RewardItem[1].Base =2802
QI44.RewardItem[1].Append =[40,60,-1,-1,-1]
QI44.RewardItem[1].BaseLv =2
QI44.RewardItem[1].AppendLv =1
QI44.RewardItem[1].Overlap =1
QI44.RewardItem[1].Binding =1
QI44.RewardItem[2].Base =2802
QI44.RewardItem[2].Append =[0,110,-1,-1,-1]
QI44.RewardItem[2].BaseLv =2
QI44.RewardItem[2].AppendLv =1
QI44.RewardItem[2].Overlap =1
QI44.RewardItem[2].Binding =1
QR44.QuestID =44
QR44.EXP =1000

# 45
QI45.QuestID =45
QI45.QuestSort =0
QI45.PrevQuestId =44
QI45.NextQuestId =46
QI45.MinLevel =29
QI45.RequiredFaction =0
QI45.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI45.Color =0
QI45.Repeat =1
QR45.QuestID =45
QR45.EXP =1500
QR45.SkillPoint =1

# 46
QI46.QuestID =46
QI46.QuestSort =0
QI46.PrevQuestId =45
QI46.NextQuestId =47
QI46.MinLevel =29
QI46.RequiredFaction =0
QI46.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI46.Color =0
QI46.Repeat =1
QR46.QuestID =46
QR46.EXP =700

# 47
QI47.QuestID =47
QI47.QuestSort =0
QI47.PrevQuestId =46
QI47.NextQuestId =48
QI47.MinLevel =30
QI47.RequiredFaction =0
QI47.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI47.Color =0
QI47.Repeat =1
QI47.RequiredLevel =30
QR47.QuestID =47
QR47.EXP =1000

# 48
QI48.QuestID =48
QI48.QuestSort =0
QI48.PrevQuestId =47
QI48.NextQuestId =49
QI48.MinLevel =30
QI48.RequiredFaction =0
QI48.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI48.Color =0
QI48.Creature =[1039,-1,-1,-1]
QI48.CreatureCount =[30,-1,-1,-1]
QI48.Repeat =1
QR48.QuestID =48
QR48.EXP =3000
QR48.SkillPoint =2

# 49
QI49.QuestID =49
QI49.QuestSort =0
QI49.PrevQuestId =48
QI49.NextQuestId =50
QI49.MinLevel =31
QI49.RequiredFaction =0
QI49.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI49.Color =0
QI49.Creature =[1040,-1,-1,-1]
QI49.CreatureCount =[30,-1,-1,-1]
QI49.Repeat =1
QI49.RewardItem[0].Base =2902
QI49.RewardItem[0].Append =[50,100,-1,-1,-1]
QI49.RewardItem[0].BaseLv =2
QI49.RewardItem[0].AppendLv =1
QI49.RewardItem[0].Overlap =1
QI49.RewardItem[0].Binding =1
QI49.RewardItem[1].Base =2902
QI49.RewardItem[1].Append =[50,130,-1,-1,-1]
QI49.RewardItem[1].BaseLv =2
QI49.RewardItem[1].AppendLv =1
QI49.RewardItem[1].Overlap =1
QI49.RewardItem[1].Binding =1
QR49.QuestID =49
QR49.EXP =3500
QR49.SkillPoint =2

# 50
QI50.QuestID =50
QI50.QuestSort =0
QI50.PrevQuestId =49
QI50.NextQuestId =51
QI50.MinLevel =32
QI50.RequiredFaction =0
QI50.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI50.Color =0
QI50.Repeat =1
QI50.RequiredLevel =33
QR50.QuestID =50
QR50.EXP =1000

# 51
QI51.QuestID =51
QI51.QuestSort =0
QI51.PrevQuestId =50
QI51.NextQuestId =52
QI51.MinLevel =33
QI51.RequiredFaction =0
QI51.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI51.Color =0
QI51.Item =[505,-1,-1,-1]
QI51.ItemCount =[1,-1,-1,-1]
QI51.ItemProbability =[8,-1,-1,-1]
QI51.Repeat =1
QI51.RewardMoney =2000
QR51.QuestID =51
QR51.EXP =4000
QR51.SkillPoint =2

# 52
QI52.QuestID =52
QI52.QuestSort =0
QI52.PrevQuestId =51
QI52.NextQuestId =53
QI52.MinLevel =33
QI52.RequiredFaction =0
QI52.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI52.Color =0
QI52.Repeat =1
QI52.RewardItem[0].Base =2301
QI52.RewardItem[0].Append =[110,180,-1,-1,-1]
QI52.RewardItem[0].BaseLv =2
QI52.RewardItem[0].AppendLv =2
QI52.RewardItem[0].Overlap =1
QI52.RewardItem[0].Binding =1
QI52.RewardItem[1].Base =2401
QI52.RewardItem[1].Append =[110,180,-1,-1,-1]
QI52.RewardItem[1].BaseLv =2
QI52.RewardItem[1].AppendLv =2
QI52.RewardItem[1].Overlap =1
QI52.RewardItem[1].Binding =1
QI52.RewardItem[2].Base =2501
QI52.RewardItem[2].Append =[60,180,-1,-1,-1]
QI52.RewardItem[2].BaseLv =2
QI52.RewardItem[2].AppendLv =2
QI52.RewardItem[2].Overlap =1
QI52.RewardItem[2].Binding =1
QR52.QuestID =52
QR52.EXP =1100

# 53
QI53.QuestID =53
QI53.QuestSort =0
QI53.PrevQuestId =52
QI53.NextQuestId =54
QI53.MinLevel =33
QI53.RequiredFaction =0
QI53.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI53.Color =0
QI53.Repeat =1
QI53.RewardMoney =2000
QR53.QuestID =53
QR53.EXP =1500
QR53.SkillPoint =1

# 54
QI54.QuestID =54
QI54.QuestSort =0
QI54.PrevQuestId =53
QI54.NextQuestId =55
QI54.MinLevel =34
QI54.RequiredFaction =0
QI54.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI54.Color =0
QI54.Repeat =1
QR54.QuestID =54
QR54.EXP =1000

# 55
QI55.QuestID =55
QI55.QuestSort =0
QI55.PrevQuestId =54
QI55.NextQuestId =56
QI55.MinLevel =34
QI55.RequiredFaction =0
QI55.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI55.Color =0
QI55.Repeat =1
QR55.QuestID =55
QR55.EXP =1000

# 56
QI56.QuestID =56
QI56.QuestSort =0
QI56.PrevQuestId =55
QI56.NextQuestId =57
QI56.MinLevel =34
QI56.RequiredFaction =0
QI56.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI56.Color =0
QI56.Repeat =1
QI56.RequiredLevel =35
QR56.QuestID =56
QR56.EXP =1200

# 57
QI57.QuestID =57
QI57.QuestSort =0
QI57.PrevQuestId =56
QI57.NextQuestId =58
QI57.MinLevel =35
QI57.RequiredFaction =0
QI57.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI57.Color =0
QI57.Item =[506,-1,-1,-1]
QI57.ItemCount =[3,-1,-1,-1]
QI57.ItemProbability =[15,-1,-1,-1]
QI57.Repeat =1
QR57.QuestID =57
QR57.EXP =3000
QR57.SkillPoint =2

# 58
QI58.QuestID =58
QI58.QuestSort =0
QI58.PrevQuestId =57
QI58.NextQuestId =59
QI58.MinLevel =35
QI58.RequiredFaction =0
QI58.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI58.Color =0
QI58.Repeat =1
QR58.QuestID =58
QR58.EXP =1000

# 59
QI59.QuestID =59
QI59.QuestSort =0
QI59.PrevQuestId =58
QI59.NextQuestId =60
QI59.MinLevel =36
QI59.RequiredFaction =0
QI59.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI59.Color =0
QI59.Repeat =1
QI59.RewardItem[0].Base =3203
QI59.RewardItem[0].Append =[60,130,-1,-1,-1]
QI59.RewardItem[0].BaseLv =2
QI59.RewardItem[0].AppendLv =2
QI59.RewardItem[0].Overlap =1
QI59.RewardItem[0].Binding =1
QI59.RewardItem[1].Base =3203
QI59.RewardItem[1].Append =[90,130,-1,-1,-1]
QI59.RewardItem[1].BaseLv =2
QI59.RewardItem[1].AppendLv =2
QI59.RewardItem[1].Overlap =1
QI59.RewardItem[1].Binding =1
QR59.QuestID =59
QR59.EXP =1200

# 60
QI60.QuestID =60
QI60.QuestSort =0
QI60.PrevQuestId =59
QI60.NextQuestId =61
QI60.MinLevel =36
QI60.RequiredFaction =0
QI60.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI60.Color =0
QI60.Repeat =1
QI60.RewardMoney =2000
QR60.QuestID =60
QR60.EXP =1500

# 61
QI61.QuestID =61
QI61.QuestSort =0
QI61.PrevQuestId =60
QI61.NextQuestId =62
QI61.MinLevel =37
QI61.RequiredFaction =0
QI61.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI61.Color =0
QI61.Repeat =1
QI61.RequiredLevel =37
QR61.QuestID =61
QR61.EXP =1200

# 62
QI62.QuestID =62
QI62.QuestSort =0
QI62.PrevQuestId =61
QI62.NextQuestId =63
QI62.MinLevel =37
QI62.RequiredFaction =0
QI62.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI62.Color =0
QI62.Creature =[1042,-1,-1,-1]
QI62.CreatureCount =[35,-1,-1,-1]
QI62.Repeat =1
QI62.RewardItem[0].Base =1003
QI62.RewardItem[0].Append =[0,40,150,-1,-1]
QI62.RewardItem[0].BaseLv =2
QI62.RewardItem[0].AppendLv =1
QI62.RewardItem[0].Overlap =1
QI62.RewardItem[0].Binding =1
QI62.RewardItem[1].Base =1403
QI62.RewardItem[1].Append =[0,40,150,-1,-1]
QI62.RewardItem[1].BaseLv =2
QI62.RewardItem[1].AppendLv =1
QI62.RewardItem[1].Overlap =1
QI62.RewardItem[1].Binding =1
QI62.RewardItem[2].Base =1703
QI62.RewardItem[2].Append =[20,40,160,-1,-1]
QI62.RewardItem[2].BaseLv =2
QI62.RewardItem[2].AppendLv =1
QI62.RewardItem[2].Overlap =1
QI62.RewardItem[2].Binding =1
QI62.RewardItem[3].Base =1803
QI62.RewardItem[3].Append =[20,40,160,-1,-1]
QI62.RewardItem[3].BaseLv =2
QI62.RewardItem[3].AppendLv =1
QI62.RewardItem[3].Overlap =1
QI62.RewardItem[3].Binding =1
QR62.QuestID =62
QR62.EXP =5000
QR62.SkillPoint =3

# 63
QI63.QuestID =63
QI63.QuestSort =0
QI63.PrevQuestId =62
QI63.NextQuestId =64
QI63.MinLevel =38
QI63.RequiredFaction =0
QI63.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI63.Color =0
QI63.Repeat =1
QI63.RequiredLevel =39
QR63.QuestID =63
QR63.EXP =1300

# 64
QI64.QuestID =64
QI64.QuestSort =0
QI64.PrevQuestId =63
QI64.NextQuestId =65
QI64.MinLevel =39
QI64.RequiredFaction =0
QI64.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI64.Color =0
QI64.Creature =[1043,-1,-1,-1]
QI64.CreatureCount =[35,-1,-1,-1]
QI64.Repeat =1
QR64.QuestID =64
QR64.EXP =6000
QR64.SkillPoint =3

# 65
QI65.QuestID =65
QI65.QuestSort =0
QI65.PrevQuestId =64
QI65.NextQuestId =66
QI65.MinLevel =40
QI65.RequiredFaction =0
QI65.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI65.Color =0
QI65.Repeat =1
QR65.QuestID =65
QR65.EXP =1300

# 66
QI66.QuestID =66
QI66.QuestSort =0
QI66.PrevQuestId =65
QI66.NextQuestId =67
QI66.MinLevel =41
QI66.RequiredFaction =0
QI66.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI66.Color =0
QI66.Repeat =1
QI66.RewardItem[0].Base =5801
QI66.RewardItem[0].Overlap =1
QI66.RewardItem[0].Binding =1
QR66.QuestID =66
QR66.EXP =1300

# 67
QI67.QuestID =67
QI67.QuestSort =0
QI67.PrevQuestId =66
QI67.NextQuestId =68
QI67.MinLevel =42
QI67.RequiredFaction =0
QI67.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI67.Color =0
QI67.Repeat =1
QI67.RequiredLevel =44
QR67.QuestID =67
QR67.EXP =1500

# 68
QI68.QuestID =68
QI68.QuestSort =0
QI68.PrevQuestId =67
QI68.NextQuestId =69
QI68.MinLevel =44
QI68.RequiredFaction =0
QI68.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI68.Color =0
QI68.Creature =[1044,-1,-1,-1]
QI68.CreatureCount =[40,-1,-1,-1]
QI68.Repeat =1
QI68.RewardItem[0].Base =4210
QI68.RewardItem[0].Overlap =5
QI68.RewardItem[0].Binding =1
QI68.RewardItem[1].Base =4220
QI68.RewardItem[1].Overlap =5
QI68.RewardItem[1].Binding =1
QR68.QuestID =68
QR68.EXP =3000
QR68.SkillPoint =2

# 69
QI69.QuestID =69
QI69.QuestSort =0
QI69.PrevQuestId =68
QI69.NextQuestId =70
QI69.MinLevel =45
QI69.RequiredFaction =0
QI69.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI69.Color =0
QI69.Repeat =1
QI69.RequiredLevel =47
QR69.QuestID =69
QR69.EXP =3000
QR69.SkillPoint =2

# 70
QI70.QuestID =70
QI70.QuestSort =0
QI70.PrevQuestId =69
QI70.NextQuestId =71
QI70.MinLevel =47
QI70.RequiredFaction =0
QI70.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI70.Color =0
QI70.Creature =[1061,-1,-1,-1]
QI70.CreatureCount =[45,-1,-1,-1]
QI70.Repeat =1
QI70.RewardItem[0].Base =4201
QI70.RewardItem[0].Overlap =1
QI70.RewardItem[0].Binding =1
QI70.RewardItem[1].Base =4211
QI70.RewardItem[1].Overlap =2
QI70.RewardItem[1].Binding =1
QI70.RewardItem[2].Base =4221
QI70.RewardItem[2].Overlap =2
QI70.RewardItem[2].Binding =1
QR70.QuestID =70
QR70.EXP =6000
QR70.SkillPoint =3

# 71
QI71.QuestID =71
QI71.QuestSort =0
QI71.PrevQuestId =70
QI71.NextQuestId =72
QI71.MinLevel =48
QI71.RequiredFaction =0
QI71.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI71.Color =0
QI71.Repeat =1
QR71.QuestID =71
QR71.EXP =2000

# 72
QI72.QuestID =72
QI72.QuestSort =0
QI72.PrevQuestId =71
QI72.NextQuestId =73
QI72.MinLevel =49
QI72.RequiredFaction =0
QI72.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI72.Color =0
QI72.Repeat =1
QR72.QuestID =72
QR72.EXP =1600

# 73
QI73.QuestID =73
QI73.QuestSort =0
QI73.PrevQuestId =72
QI73.NextQuestId =74
QI73.MinLevel =50
QI73.RequiredFaction =0
QI73.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI73.Color =0
QI73.Repeat =1
QI73.RewardItem[0].Base =2104
QI73.RewardItem[0].Append =[11,-1,-1,-1,-1]
QI73.RewardItem[0].BaseLv =2
QI73.RewardItem[0].AppendLv =4
QI73.RewardItem[0].Overlap =1
QI73.RewardItem[0].Binding =1
QI73.RewardItem[1].Base =2204
QI73.RewardItem[1].Append =[31,-1,-1,-1,-1]
QI73.RewardItem[1].BaseLv =2
QI73.RewardItem[1].AppendLv =4
QI73.RewardItem[1].Overlap =1
QI73.RewardItem[1].Binding =1
QR73.QuestID =73
QR73.EXP =1600

# 74
QI74.QuestID =74
QI74.QuestSort =0
QI74.PrevQuestId =73
QI74.NextQuestId =75
QI74.MinLevel =51
QI74.RequiredFaction =0
QI74.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI74.Color =0
QI74.Repeat =1
QI74.RequiredLevel =52
QR74.QuestID =74
QR74.EXP =1800

# 75
QI75.QuestID =75
QI75.QuestSort =0
QI75.PrevQuestId =74
QI75.NextQuestId =76
QI75.MinLevel =52
QI75.RequiredFaction =0
QI75.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI75.Color =0
QI75.Item =[507,-1,-1,-1]
QI75.ItemCount =[10,-1,-1,-1]
QI75.ItemProbability =[25,-1,-1,-1]
QI75.Repeat =1
QR75.QuestID =75
QR75.EXP =8000
QR75.SkillPoint =4

# 76
QI76.QuestID =76
QI76.QuestSort =0
QI76.PrevQuestId =75
QI76.NextQuestId =77
QI76.MinLevel =53
QI76.RequiredFaction =0
QI76.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI76.Color =0
QI76.Repeat =1
QI76.RewardItem[0].Base =2302
QI76.RewardItem[0].Append =[131,-1,-1,-1,-1]
QI76.RewardItem[0].BaseLv =2
QI76.RewardItem[0].AppendLv =3
QI76.RewardItem[0].Overlap =1
QI76.RewardItem[0].Binding =1
QI76.RewardItem[1].Base =2402
QI76.RewardItem[1].Append =[141,-1,-1,-1,-1]
QI76.RewardItem[1].BaseLv =2
QI76.RewardItem[1].AppendLv =3
QI76.RewardItem[1].Overlap =1
QI76.RewardItem[1].Binding =1
QI76.RewardItem[2].Base =2502
QI76.RewardItem[2].Append =[40,60,-1,-1,-1]
QI76.RewardItem[2].BaseLv =2
QI76.RewardItem[2].AppendLv =2
QI76.RewardItem[2].Overlap =1
QI76.RewardItem[2].Binding =1
QR76.QuestID =76
QR76.EXP =1800

# 77
QI77.QuestID =77
QI77.QuestSort =0
QI77.PrevQuestId =76
QI77.NextQuestId =78
QI77.MinLevel =54
QI77.RequiredFaction =0
QI77.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI77.Color =0
QI77.Repeat =1
QR77.QuestID =77
QR77.EXP =1900

# 78
QI78.QuestID =78
QI78.QuestSort =0
QI78.PrevQuestId =77
QI78.NextQuestId =79
QI78.MinLevel =55
QI78.RequiredFaction =0
QI78.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI78.Color =0
QI78.Repeat =1
QI78.RewardItem[0].Base =2602
QI78.RewardItem[0].Append =[70,120,151,-1,-1]
QI78.RewardItem[0].BaseLv =2
QI78.RewardItem[0].AppendLv =2
QI78.RewardItem[0].Overlap =1
QI78.RewardItem[0].Binding =1
QR78.QuestID =78
QR78.EXP =2000

# 79
QI79.QuestID =79
QI79.QuestSort =0
QI79.PrevQuestId =78
QI79.NextQuestId =80
QI79.MinLevel =56
QI79.RequiredFaction =0
QI79.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI79.Color =0
QI79.Repeat =1
QI79.RequiredLevel =57
QR79.QuestID =79
QR79.EXP =3000

# 80
QI80.QuestID =80
QI80.QuestSort =0
QI80.PrevQuestId =79
QI80.NextQuestId =81
QI80.MinLevel =57
QI80.RequiredFaction =0
QI80.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI80.Color =0
QI80.Creature =[1065,-1,-1,-1]
QI80.CreatureCount =[50,-1,-1,-1]
QI80.Repeat =1
QI80.RewardItem[0].Base =2702
QI80.RewardItem[0].Append =[70,120,170,-1,-1]
QI80.RewardItem[0].BaseLv =2
QI80.RewardItem[0].AppendLv =2
QI80.RewardItem[0].Overlap =1
QI80.RewardItem[0].Binding =1
QR80.QuestID =80
QR80.EXP =10000
QR80.SkillPoint =4

# 81
QI81.QuestID =81
QI81.QuestSort =0
QI81.PrevQuestId =80
QI81.NextQuestId =82
QI81.MinLevel =58
QI81.RequiredFaction =0
QI81.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI81.Color =0
QI81.Repeat =1
QR81.QuestID =81
QR81.EXP =2000

# 82
QI82.QuestID =82
QI82.QuestSort =0
QI82.PrevQuestId =81
QI82.NextQuestId =83
QI82.MinLevel =59
QI82.RequiredFaction =0
QI82.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI82.Color =0
QI82.Repeat =1
QI82.RequiredLevel =60
QR82.QuestID =82
QR82.EXP =2100

# 83
QI83.QuestID =83
QI83.QuestSort =0
QI83.PrevQuestId =82
QI83.NextQuestId =84
QI83.MinLevel =60
QI83.RequiredFaction =0
QI83.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI83.Color =0
QI83.Item =[508,-1,-1,-1]
QI83.ItemCount =[20,-1,-1,-1]
QI83.ItemProbability =[35,-1,-1,-1]
QI83.Repeat =1
QR83.QuestID =83
QR83.EXP =12000
QR83.SkillPoint =4

# 84
QI84.QuestID =84
QI84.QuestSort =0
QI84.PrevQuestId =83
QI84.NextQuestId =85
QI84.MinLevel =62
QI84.RequiredFaction =0
QI84.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI84.Color =0
QI84.Repeat =1
QI84.RewardItem[0].Base =3206
QI84.RewardItem[0].Append =[1,80,-1,-1,-1]
QI84.RewardItem[0].BaseLv =2
QI84.RewardItem[0].AppendLv =3
QI84.RewardItem[0].Overlap =1
QI84.RewardItem[0].Binding =1
QI84.RewardItem[1].Base =3206
QI84.RewardItem[1].Append =[21,90,-1,-1,-1]
QI84.RewardItem[1].BaseLv =2
QI84.RewardItem[1].AppendLv =3
QI84.RewardItem[1].Overlap =1
QI84.RewardItem[1].Binding =1
QR84.QuestID =84
QR84.EXP =3000
QR84.SkillPoint =1

# 85
QI85.QuestID =85
QI85.QuestSort =0
QI85.PrevQuestId =84
QI85.NextQuestId =86
QI85.MinLevel =64
QI85.RequiredFaction =0
QI85.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI85.Color =0
QI85.Repeat =1
QR85.QuestID =85
QR85.EXP =2200

# 86
QI86.QuestID =86
QI86.QuestSort =0
QI86.PrevQuestId =85
QI86.NextQuestId =87
QI86.MinLevel =66
QI86.RequiredFaction =0
QI86.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI86.Color =0
QI86.Money =100
QI86.Repeat =1
QI86.RequiredLevel =68
QR86.QuestID =86
QR86.EXP =2400

# 87
QI87.QuestID =87
QI87.QuestSort =0
QI87.PrevQuestId =86
QI87.NextQuestId =88
QI87.MinLevel =68
QI87.RequiredFaction =0
QI87.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI87.Color =0
QI87.Item =[509,-1,-1,-1]
QI87.ItemCount =[20,-1,-1,-1]
QI87.ItemProbability =[35,-1,-1,-1]
QI87.Repeat =1
QR87.QuestID =87
QR87.EXP =15000
QR87.SkillPoint =5

# 88
QI88.QuestID =88
QI88.QuestSort =0
QI88.PrevQuestId =87
QI88.NextQuestId =89
QI88.MinLevel =70
QI88.RequiredFaction =0
QI88.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI88.Color =0
QI88.Repeat =1
QR88.QuestID =88
QR88.EXP =4000
QR88.SkillPoint =1

# 89
QI89.QuestID =89
QI89.QuestSort =0
QI89.PrevQuestId =88
QI89.NextQuestId =90
QI89.MinLevel =72
QI89.RequiredFaction =0
QI89.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI89.Color =0
QI89.Repeat =1
QR89.QuestID =89
QR89.EXP =5000

# 90
QI90.QuestID =90
QI90.QuestSort =0
QI90.PrevQuestId =89
QI90.NextQuestId =91
QI90.MinLevel =74
QI90.RequiredFaction =0
QI90.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI90.Color =0
QI90.Repeat =1
QR90.QuestID =90
QR90.EXP =5000

# 91
QI91.QuestID =91
QI91.QuestSort =0
QI91.PrevQuestId =90
QI91.NextQuestId =92
QI91.MinLevel =75
QI91.RequiredFaction =0
QI91.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI91.Color =0
QI91.Repeat =1
QR91.QuestID =91
QR91.EXP =3000

# 92
QI92.QuestID =92
QI92.QuestSort =0
QI92.PrevQuestId =91
QI92.NextQuestId =93
QI92.MinLevel =77
QI92.RequiredFaction =0
QI92.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI92.Color =0
QI92.Repeat =1
QI92.RequiredLevel =79
QR92.QuestID =92
QR92.EXP =3500

# 93
QI93.QuestID =93
QI93.QuestSort =0
QI93.PrevQuestId =92
QI93.NextQuestId =94
QI93.MinLevel =79
QI93.RequiredFaction =0
QI93.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI93.Color =0
QI93.Creature =[1082,-1,-1,-1]
QI93.CreatureCount =[70,-1,-1,-1]
QI93.Repeat =1
QI93.RewardItem[0].Base =2503
QI93.RewardItem[0].Append =[131,141,-1,-1,-1]
QI93.RewardItem[0].BaseLv =1
QI93.RewardItem[0].AppendLv =1
QI93.RewardItem[0].Overlap =1
QI93.RewardItem[0].Binding =1
QR93.QuestID =93
QR93.EXP =20000
QR93.SkillPoint =5

# 94
QI94.QuestID =94
QI94.QuestSort =0
QI94.PrevQuestId =93
QI94.NextQuestId =95
QI94.MinLevel =80
QI94.RequiredFaction =0
QI94.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI94.Color =0
QI94.Repeat =1
QI94.RequiredLevel =82
QR94.QuestID =94
QR94.EXP =4000

# 95
QI95.QuestID =95
QI95.QuestSort =0
QI95.PrevQuestId =94
QI95.NextQuestId =96
QI95.MinLevel =82
QI95.RequiredFaction =0
QI95.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI95.Color =0
QI95.Creature =[1084,-1,-1,-1]
QI95.CreatureCount =[75,-1,-1,-1]
QI95.Repeat =1
QI95.RewardItem[0].Base =3004
QI95.RewardItem[0].Append =[12,32,-1,-1,-1]
QI95.RewardItem[0].BaseLv =2
QI95.RewardItem[0].AppendLv =2
QI95.RewardItem[0].Overlap =1
QI95.RewardItem[0].Binding =1
QR95.QuestID =95
QR95.EXP =25000
QR95.SkillPoint =4

# 96
QI96.QuestID =96
QI96.QuestSort =0
QI96.PrevQuestId =95
QI96.NextQuestId =97
QI96.MinLevel =85
QI96.RequiredFaction =0
QI96.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI96.Color =0
QI96.Repeat =1
QI96.RequiredLevel =87
QR96.QuestID =96
QR96.EXP =5000

# 97
QI97.QuestID =97
QI97.QuestSort =0
QI97.PrevQuestId =96
QI97.NextQuestId =98
QI97.MinLevel =87
QI97.RequiredFaction =0
QI97.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI97.Color =0
QI97.Creature =[1085,-1,-1,-1]
QI97.CreatureCount =[75,-1,-1,-1]
QI97.Repeat =1
QI97.RewardItem[0].Base =3104
QI97.RewardItem[0].Append =[102,142,170,-1,-1]
QI97.RewardItem[0].BaseLv =3
QI97.RewardItem[0].AppendLv =1
QI97.RewardItem[0].Overlap =1
QI97.RewardItem[0].Binding =1
QI97.RewardItem[1].Base =3104
QI97.RewardItem[1].Append =[50,70,120,-1,-1]
QI97.RewardItem[1].BaseLv =3
QI97.RewardItem[1].AppendLv =1
QI97.RewardItem[1].Overlap =1
QI97.RewardItem[1].Binding =1
QR97.QuestID =97
QR97.EXP =30000
QR97.SkillPoint =5

# 98
QI98.QuestID =98
QI98.QuestSort =0
QI98.PrevQuestId =97
QI98.NextQuestId =99
QI98.MinLevel =89
QI98.RequiredFaction =0
QI98.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI98.Color =0
QI98.Repeat =1
QR98.QuestID =98
QR98.EXP =5000

# 99
QI99.QuestID =99
QI99.QuestSort =0
QI99.PrevQuestId =98
QI99.NextQuestId =100
QI99.MinLevel =90
QI99.RequiredFaction =0
QI99.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI99.Color =0
QI99.Repeat =1
QI99.RequiredLevel =91
QR99.QuestID =99
QR99.EXP =5000

# 100
QI100.QuestID =100
QI100.QuestSort =0
QI100.PrevQuestId =99
QI100.NextQuestId =-1
QI100.MinLevel =91
QI100.RequiredFaction =0
QI100.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI100.Color =0
QI100.Creature =[1101,-1,-1,-1]
QI100.CreatureCount =[80,-1,-1,-1]
QI100.Repeat =1
QI100.RewardItem[0].Base =4232
QI100.RewardItem[0].Overlap =1
QI100.RewardItem[0].Binding =1
QR100.QuestID =100
QR100.EXP =35000
QR100.SkillPoint =5

# 101
QI101.QuestID =101
QI101.QuestSort =1
QI101.NextQuestId =102
QI101.MinLevel =10
QI101.RequiredFaction =0
QI101.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI101.Color =0
QI101.Creature =[1028,-1,-1,-1]
QI101.CreatureCount =[20,-1,-1,-1]
QI101.Repeat =1
QR101.QuestID =101
QR101.EXP =600

# 102
QI102.QuestID =102
QI102.QuestSort =1
QI102.PrevQuestId =101
QI102.NextQuestId =103
QI102.MinLevel =40
QI102.RequiredFaction =0
QI102.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI102.Color =0
QI102.Creature =[1046,-1,-1,-1]
QI102.CreatureCount =[30,-1,-1,-1]
QI102.Repeat =1
QR102.QuestID =102
QR102.EXP =7800
QR102.SkillPoint =2

# 103
QI103.QuestID =103
QI103.QuestSort =1
QI103.PrevQuestId =102
QI103.NextQuestId =104
QI103.MinLevel =50
QI103.RequiredFaction =0
QI103.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI103.Color =1
QI103.Creature =[1064,-1,-1,-1]
QI103.CreatureCount =[50,-1,-1,-1]
QI103.Repeat =1
QR103.QuestID =103
QR103.EXP =30000
QR103.SkillPoint =8

# 104
QI104.QuestID =104
QI104.QuestSort =1
QI104.PrevQuestId =103
QI104.NextQuestId =105
QI104.MinLevel =80
QI104.RequiredFaction =0
QI104.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI104.Color =0
QI104.Creature =[1084,-1,-1,-1]
QI104.CreatureCount =[70,-1,-1,-1]
QI104.Repeat =1
QR104.QuestID =104
QR104.EXP =50000
QR104.SkillPoint =8

# 105
QI105.QuestID =105
QI105.QuestSort =1
QI105.PrevQuestId =104
QI105.NextQuestId =106
QI105.MinLevel =90
QI105.RequiredFaction =0
QI105.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI105.Color =1
QI105.Creature =[1101,-1,-1,-1]
QI105.CreatureCount =[90,-1,-1,-1]
QI105.Repeat =1
QR105.QuestID =105
QR105.EXP =95000
QR105.SkillPoint =14

# 106
QI106.QuestID =106
QI106.QuestSort =1
QI106.PrevQuestId =105
QI106.MinLevel =100
QI106.RequiredFaction =0
QI106.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI106.Color =2
QI106.Creature =[1104,-1,-1,-1]
QI106.CreatureCount =[100,-1,-1,-1]
QI106.Repeat =1
QR106.QuestID =106
QR106.EXP =140000
QR106.SkillPoint =20

# 107
QI107.QuestID =107
QI107.QuestSort =1
QI107.NextQuestId =108
QI107.MinLevel =20
QI107.RequiredFaction =0
QI107.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI107.Color =0
QI107.Repeat =1
QI107.RewardMoney =1000
QR107.QuestID =107
QR107.EXP =500

# 108
QI108.QuestID =108
QI108.QuestSort =1
QI108.PrevQuestId =107
QI108.NextQuestId =109
QI108.MinLevel =22
QI108.RequiredFaction =0
QI108.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI108.Color =0
QI108.Repeat =1
QI108.RewardMoney =1000
QR108.QuestID =108
QR108.EXP =1000

# 109
QI109.QuestID =109
QI109.QuestSort =1
QI109.PrevQuestId =108
QI109.MinLevel =40
QI109.RequiredFaction =0
QI109.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI109.Color =1
QI109.Item =[510,-1,-1,-1]
QI109.ItemCount =[1,-1,-1,-1]
QI109.ItemProbability =[8,-1,-1,-1]
QI109.Repeat =1
QR109.QuestID =109
QR109.EXP =12000
QR109.SkillPoint =4

# 110
QI110.QuestID =110
QI110.QuestSort =1
QI110.NextQuestsId =111,-1
QI110.MinLevel =50
QI110.RequiredFaction =0
QI110.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI110.Color =0
QI110.Creature =[1065,-1,-1,-1]
QI110.CreatureCount =[50,-1,-1,-1]
QI110.Repeat =1
QR110.QuestID =110
QR110.EXP =21000
QR110.SkillPoint =5

# 111
QI111.QuestID =111
QI111.QuestSort =1
QI111.PrevQuestId =110
QI111.NextQuestId =112
QI111.MinLevel =60
QI111.RequiredFaction =0
QI111.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI111.Color =0
QI111.Repeat =1
QR111.QuestID =111
QR111.EXP =2000

# 112
QI112.QuestID =112
QI112.QuestSort =1
QI112.PrevQuestId =111
QI112.MinLevel =75
QI112.RequiredFaction =0
QI112.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI112.Color =1
QI112.Creature =[1083,-1,-1,-1]
QI112.CreatureCount =[70,-1,-1,-1]
QI112.Repeat =1
QR112.QuestID =112
QR112.EXP =64000
QR112.SkillPoint =11

# 113
QI113.QuestID =113
QI113.QuestSort =1
QI113.NextQuestId =114
QI113.MinLevel =100
QI113.RequiredFaction =0
QI113.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI113.Color =0
QI113.Repeat =1
QR113.QuestID =113
QR113.EXP =10000

# 114
QI114.QuestID =114
QI114.QuestSort =1
QI114.PrevQuestId =113
QI114.NextQuestId =115
QI114.MinLevel =101
QI114.RequiredFaction =0
QI114.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI114.Color =0
QI114.Repeat =1
QR114.QuestID =114
QR114.EXP =20000

# 115
QI115.QuestID =115
QI115.QuestSort =1
QI115.PrevQuestId =114
QI115.MinLevel =99
QI115.RequiredFaction =0
QI115.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI115.Color =1
QI115.Item =[520,-1,-1,-1]
QI115.ItemCount =[1,-1,-1,-1]
QI115.ItemProbability =[8,-1,-1,-1]
QI115.Repeat =1
QR115.QuestID =115
QR115.EXP =30000
QR115.SkillPoint =5

# 116
QI116.QuestID =116
QI116.QuestSort =2
QI116.MinLevel =25
QI116.RequiredFaction =0
QI116.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI116.Color =2
QI116.Creature =[1026,-1,-1,-1]
QI116.CreatureCount =[1,-1,-1,-1]
QI116.Repeat =1
QI116.RewardMoney =2000
QR116.QuestID =116
QR116.EXP =30000
QR116.SkillPoint =12

# 117
QI117.QuestID =117
QI117.QuestSort =2
QI117.MinLevel =36
QI117.RequiredFaction =0
QI117.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI117.Color =1
QI117.Creature =[1046,-1,-1,-1]
QI117.CreatureCount =[40,-1,-1,-1]
QI117.Repeat =1
QI117.RewardMoney =2000
QR117.QuestID =117
QR117.EXP =22000
QR117.SkillPoint =6

# 118
QI118.QuestID =118
QI118.QuestSort =2
QI118.MinLevel =56
QI118.RequiredFaction =0
QI118.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI118.Color =2
QI118.Creature =[1063,-1,-1,-1]
QI118.CreatureCount =[1,-1,-1,-1]
QI118.Repeat =1
QI118.RewardMoney =5000
QR118.QuestID =118
QR118.EXP =80000
QR118.SkillPoint =20

# 119
QI119.QuestID =119
QI119.QuestSort =2
QI119.MinLevel =70
QI119.RequiredFaction =0
QI119.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI119.Color =1
QI119.Creature =[1080,-1,-1,-1]
QI119.CreatureCount =[60,-1,-1,-1]
QI119.Repeat =1
QI119.RewardMoney =5000
QR119.QuestID =119
QR119.EXP =50000
QR119.SkillPoint =9

# 120
QI120.QuestID =120
QI120.QuestSort =2
QI120.MinLevel =72
QI120.RequiredFaction =0
QI120.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI120.Color =1
QI120.Creature =[1081,-1,-1,-1]
QI120.CreatureCount =[70,-1,-1,-1]
QI120.Repeat =1
QI120.RewardMoney =6000
QR120.QuestID =120
QR120.EXP =60000
QR120.SkillPoint =11

# 121
QI121.QuestID =121
QI121.QuestSort =2
QI121.MinLevel =90
QI121.RequiredFaction =0
QI121.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI121.Color =1
QI121.Creature =[1102,-1,-1,-1]
QI121.CreatureCount =[80,-1,-1,-1]
QI121.Repeat =1
QI121.RewardMoney =10000
QR121.QuestID =121
QR121.EXP =110000
QR121.SkillPoint =16

# 122
QI122.QuestID =122
QI122.QuestSort =2
QI122.MinLevel =100
QI122.RequiredFaction =0
QI122.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI122.Color =3
QI122.Creature =[1103,-1,-1,-1]
QI122.CreatureCount =[1,-1,-1,-1]
QI122.Repeat =1
QI122.RewardMoney =20000
QR122.QuestID =122
QR122.EXP =220000
QR122.SkillPoint =30

# 123
QI123.QuestID =123
QI123.QuestSort =3
QI123.MinLevel =10
QI123.RequiredClass =0,1
QI123.RequiredFaction =0
QI123.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI123.Color =0
QI123.Repeat =1
QI123.RewardItem[0].Base =5011
QI123.RewardItem[0].Overlap =1
QI123.RewardItem[0].Binding =1
QI123.RewardItem[1].Base =5027
QI123.RewardItem[1].Overlap =1
QI123.RewardItem[1].Binding =1
QI123.RewardItem[2].Base =5211
QI123.RewardItem[2].Overlap =1
QI123.RewardItem[2].Binding =1
QI123.RewardItem[3].Base =5240
QI123.RewardItem[3].Overlap =1
QI123.RewardItem[3].Binding =1
QR123.QuestID =123
QR123.EXP =0

# 124
QI124.QuestID =124
QI124.QuestSort =3
QI124.MinLevel =30
QI124.RequiredClass =0,1
QI124.RequiredFaction =0
QI124.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI124.Color =0
QI124.Repeat =1
QI124.RewardItem[0].Base =5012
QI124.RewardItem[0].Overlap =1
QI124.RewardItem[0].Binding =1
QI124.RewardItem[1].Base =5038
QI124.RewardItem[1].Overlap =1
QI124.RewardItem[1].Binding =1
QI124.RewardItem[2].Base =5228
QI124.RewardItem[2].Overlap =1
QI124.RewardItem[2].Binding =1
QI124.RewardItem[3].Base =5236
QI124.RewardItem[3].Overlap =1
QI124.RewardItem[3].Binding =1
QR124.QuestID =124
QR124.EXP =0

# 125
QI125.QuestID =125
QI125.QuestSort =3
QI125.MinLevel =50
QI125.RequiredClass =0,1
QI125.RequiredFaction =0
QI125.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI125.Color =0
QI125.Repeat =1
QI125.RewardItem[0].Base =5023
QI125.RewardItem[0].Overlap =1
QI125.RewardItem[0].Binding =1
QI125.RewardItem[1].Base =5004
QI125.RewardItem[1].Overlap =1
QI125.RewardItem[1].Binding =1
QI125.RewardItem[2].Base =5231
QI125.RewardItem[2].Overlap =1
QI125.RewardItem[2].Binding =1
QI125.RewardItem[3].Base =5204
QI125.RewardItem[3].Overlap =1
QI125.RewardItem[3].Binding =1
QR125.QuestID =125
QR125.EXP =0

# 126
QI126.QuestID =126
QI126.QuestSort =3
QI126.MinLevel =70
QI126.RequiredClass =0,1
QI126.RequiredFaction =0
QI126.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI126.Color =0
QI126.Repeat =1
QI126.RewardItem[0].Base =5024
QI126.RewardItem[0].Overlap =1
QI126.RewardItem[0].Binding =1
QI126.RewardItem[1].Base =5007
QI126.RewardItem[1].Overlap =1
QI126.RewardItem[1].Binding =1
QI126.RewardItem[2].Base =5207
QI126.RewardItem[2].Overlap =1
QI126.RewardItem[2].Binding =1
QI126.RewardItem[3].Base =5224
QI126.RewardItem[3].Overlap =1
QI126.RewardItem[3].Binding =1
QR126.QuestID =126
QR126.EXP =0

# 127
QI127.QuestID =127
QI127.QuestSort =3
QI127.MinLevel =90
QI127.RequiredClass =0,1
QI127.RequiredFaction =0
QI127.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI127.Color =0
QI127.Repeat =1
QI127.RewardItem[0].Base =5008
QI127.RewardItem[0].Overlap =1
QI127.RewardItem[0].Binding =1
QI127.RewardItem[1].Base =5036
QI127.RewardItem[1].Overlap =1
QI127.RewardItem[1].Binding =1
QI127.RewardItem[2].Base =5208
QI127.RewardItem[2].Overlap =1
QI127.RewardItem[2].Binding =1
QI127.RewardItem[3].Base =5239
QI127.RewardItem[3].Overlap =1
QI127.RewardItem[3].Binding =1
QR127.QuestID =127
QR127.EXP =0

# 128
QI128.QuestID =128
QI128.QuestSort =3
QI128.MinLevel =40
QI128.RequiredClass =0,1
QI128.RequiredFaction =0
QI128.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI128.Color =0
QI128.Repeat =1
QI128.RewardItem[0].Base =5028
QI128.RewardItem[0].Overlap =1
QI128.RewardItem[0].Binding =1
QI128.RewardItem[1].Base =5241
QI128.RewardItem[1].Overlap =1
QI128.RewardItem[1].Binding =1
QR128.QuestID =128
QR128.EXP =0

# 129
QI129.QuestID =129
QI129.QuestSort =3
QI129.MinLevel =10
QI129.RequiredClass =2,3
QI129.RequiredFaction =0
QI129.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI129.Color =0
QI129.Repeat =1
QI129.RewardItem[0].Base =5411
QI129.RewardItem[0].Overlap =1
QI129.RewardItem[0].Binding =1
QI129.RewardItem[1].Base =5400
QI129.RewardItem[1].Overlap =1
QI129.RewardItem[1].Binding =1
QI129.RewardItem[2].Base =5605
QI129.RewardItem[2].Overlap =1
QI129.RewardItem[2].Binding =1
QI129.RewardItem[3].Base =5610
QI129.RewardItem[3].Overlap =1
QI129.RewardItem[3].Binding =1
QR129.QuestID =129
QR129.EXP =0

# 130
QI130.QuestID =130
QI130.QuestSort =3
QI130.MinLevel =30
QI130.RequiredClass =2,3
QI130.RequiredFaction =0
QI130.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI130.Color =0
QI130.Repeat =1
QI130.RewardItem[0].Base =5412
QI130.RewardItem[0].Overlap =1
QI130.RewardItem[0].Binding =1
QI130.RewardItem[1].Base =5428
QI130.RewardItem[1].Overlap =1
QI130.RewardItem[1].Binding =1
QI130.RewardItem[2].Base =5601
QI130.RewardItem[2].Overlap =1
QI130.RewardItem[2].Binding =1
QI130.RewardItem[3].Base =5616
QI130.RewardItem[3].Overlap =1
QI130.RewardItem[3].Binding =1
QR130.QuestID =130
QR130.EXP =0

# 131
QI131.QuestID =131
QI131.QuestSort =3
QI131.MinLevel =50
QI131.RequiredClass =2,3
QI131.RequiredFaction =0
QI131.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI131.Color =0
QI131.Repeat =1
QI131.RewardItem[0].Base =5433
QI131.RewardItem[0].Overlap =1
QI131.RewardItem[0].Binding =1
QI131.RewardItem[1].Base =5423
QI131.RewardItem[1].Overlap =1
QI131.RewardItem[1].Binding =1
QI131.RewardItem[2].Base =5646
QI131.RewardItem[2].Overlap =1
QI131.RewardItem[2].Binding =1
QI131.RewardItem[3].Base =5635
QI131.RewardItem[3].Overlap =1
QI131.RewardItem[3].Binding =1
QR131.QuestID =131
QR131.EXP =0

# 132
QI132.QuestID =132
QI132.QuestSort =3
QI132.MinLevel =70
QI132.RequiredClass =2,3
QI132.RequiredFaction =0
QI132.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI132.Color =0
QI132.Repeat =1
QI132.RewardItem[0].Base =5443
QI132.RewardItem[0].Overlap =1
QI132.RewardItem[0].Binding =1
QI132.RewardItem[1].Base =5407
QI132.RewardItem[1].Overlap =1
QI132.RewardItem[1].Binding =1
QI132.RewardItem[2].Base =5621
QI132.RewardItem[2].Overlap =1
QI132.RewardItem[2].Binding =1
QI132.RewardItem[3].Base =5638
QI132.RewardItem[3].Overlap =1
QI132.RewardItem[3].Binding =1
QR132.QuestID =132
QR132.EXP =0

# 133
QI133.QuestID =133
QI133.QuestSort =3
QI133.MinLevel =90
QI133.RequiredClass =2,3
QI133.RequiredFaction =0
QI133.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI133.Color =0
QI133.Repeat =1
QI133.RewardItem[0].Base =5408
QI133.RewardItem[0].Overlap =1
QI133.RewardItem[0].Binding =1
QI133.RewardItem[1].Base =5431
QI133.RewardItem[1].Overlap =1
QI133.RewardItem[1].Binding =1
QI133.RewardItem[2].Base =5639
QI133.RewardItem[2].Overlap =1
QI133.RewardItem[2].Binding =1
QI133.RewardItem[3].Base =5619
QI133.RewardItem[3].Overlap =1
QI133.RewardItem[3].Binding =1
QR133.QuestID =133
QR133.EXP =0

# 134
QI134.QuestID =134
QI134.QuestSort =3
QI134.MinLevel =40
QI134.RequiredClass =2,3
QI134.RequiredFaction =0
QI134.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI134.Color =0
QI134.Repeat =1
QI134.RewardItem[0].Base =5403
QI134.RewardItem[0].Overlap =1
QI134.RewardItem[0].Binding =1
QI134.RewardItem[1].Base =5611
QI134.RewardItem[1].Overlap =1
QI134.RewardItem[1].Binding =1
QR134.QuestID =134
QR134.EXP =0

# 135
QI135.QuestID =135
QI135.QuestSort =1
QI135.NextQuestId =136
QI135.MinLevel =2
QI135.RequiredFaction =0
QI135.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI135.Color =0
QI135.Repeat =1
QR135.QuestID =135
QR135.EXP =100

# 136
QI136.QuestID =136
QI136.QuestSort =1
QI136.PrevQuestId =135
QI136.NextQuestsId =137,-1
QI136.MinLevel =16
QI136.RequiredFaction =0
QI136.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI136.Color =0
QI136.Creature =[1024,-1,-1,-1]
QI136.CreatureCount =[20,-1,-1,-1]
QI136.Repeat =1
QR136.QuestID =136
QR136.EXP =1200

# 137
QI137.QuestID =137
QI137.QuestSort =1
QI137.PrevQuestId =136
QI137.MinLevel =30
QI137.RequiredFaction =0
QI137.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI137.Color =0
QI137.Repeat =1
QI137.RewardMoney =1000
QR137.QuestID =137
QR137.EXP =500

# 138
QI138.QuestID =138
QI138.QuestSort =1
QI138.MinLevel =40
QI138.RequiredFaction =0
QI138.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI138.Color =0
QI138.Item =[521,-1,-1,-1]
QI138.ItemCount =[1,-1,-1,-1]
QI138.ItemProbability =[8,-1,-1,-1]
QI138.Repeat =1
QR138.QuestID =138
QR138.EXP =6000
QR138.SkillPoint =1

# 139
QI139.QuestID =139
QI139.QuestSort =1
QI139.MinLevel =60
QI139.RequiredFaction =0
QI139.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI139.Color =0
QI139.Repeat =1
QR139.QuestID =139
QR139.EXP =5000

# 140
QI140.QuestID =140
QI140.QuestSort =4
QI140.NextQuestId =141
QI140.MinLevel =10
QI140.RequiredFaction =0
QI140.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI140.Color =0
QI140.Repeat =1
QR140.QuestID =140
QR140.EXP =200

# 141
QI141.QuestID =141
QI141.QuestSort =4
QI141.PrevQuestId =140
QI141.MinLevel =40
QI141.MaxLevel =50
QI141.RequiredFaction =0
QI141.MinTime =[0,1,0,-1]
QI141.MaxTime =[23,58,0,-1]
QI141.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI141.Color =0
QI141.Creature =[1043,-1,-1,-1]
QI141.CreatureCount =[25,-1,-1,-1]
QI141.Repeat =3
QR141.QuestID =141
QR141.EXP =2500
QR141.SkillPoint =3

# 142
QI142.QuestID =142
QI142.QuestSort =4
QI142.MinLevel =52
QI142.MaxLevel =70
QI142.RequiredFaction =0
QI142.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI142.Color =0
QI142.Repeat =1
QR142.QuestID =142
QR142.EXP =2000

# 143
QI143.QuestID =143
QI143.QuestSort =4
QI143.MinLevel =80
QI143.MaxLevel =98
QI143.RequiredFaction =0
QI143.MinTime =[0,1,0,-1]
QI143.MaxTime =[23,58,0,-1]
QI143.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI143.Color =0
QI143.Creature =[1085,-1,-1,-1]
QI143.CreatureCount =[80,-1,-1,-1]
QI143.Repeat =3
QR143.QuestID =143
QR143.EXP =30000
QR143.SkillPoint =9

# 144
QI144.QuestID =144
QI144.QuestSort =4
QI144.MinLevel =100
QI144.MaxLevel =118
QI144.RequiredFaction =0
QI144.MinTime =[0,1,0,-1]
QI144.MaxTime =[23,58,0,-1]
QI144.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI144.Color =0
QI144.Creature =[1118,-1,-1,-1]
QI144.CreatureCount =[100,-1,-1,-1]
QI144.Repeat =3
QR144.QuestID =144
QR144.EXP =57000
QR144.SkillPoint =14

# 145
QI145.QuestID =145
QI145.QuestSort =5
QI145.MinLevel =30
QI145.MaxLevel =40
QI145.RequiredFaction =0
QI145.MinTime =[0,1,0,-1]
QI145.MaxTime =[23,58,0,-1]
QI145.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI145.Color =0
QI145.Item =[522,-1,-1,-1]
QI145.ItemCount =[12,-1,-1,-1]
QI145.ItemProbability =[20,-1,-1,-1]
QI145.Repeat =3
QI145.RewardMoney =1000
QR145.QuestID =145
QR145.EXP =0

# 146
QI146.QuestID =146
QI146.QuestSort =5
QI146.MinLevel =50
QI146.MaxLevel =60
QI146.RequiredFaction =0
QI146.MinTime =[0,1,0,-1]
QI146.MaxTime =[23,58,0,-1]
QI146.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI146.Color =0
QI146.Item =[523,-1,-1,-1]
QI146.ItemCount =[12,-1,-1,-1]
QI146.ItemProbability =[20,-1,-1,-1]
QI146.Repeat =3
QI146.RewardMoney =3000
QR146.QuestID =146
QR146.EXP =0

# 147
QI147.QuestID =147
QI147.QuestSort =5
QI147.MinLevel =76
QI147.MaxLevel =86
QI147.RequiredFaction =0
QI147.MinTime =[0,1,0,-1]
QI147.MaxTime =[23,58,0,-1]
QI147.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI147.Color =0
QI147.Item =[524,-1,-1,-1]
QI147.ItemCount =[12,-1,-1,-1]
QI147.ItemProbability =[20,-1,-1,-1]
QI147.Repeat =3
QI147.RewardMoney =4500
QR147.QuestID =147
QR147.EXP =0

# 148
QI148.QuestID =148
QI148.QuestSort =5
QI148.MinLevel =94
QI148.MaxLevel =104
QI148.RequiredFaction =0
QI148.MinTime =[0,1,0,-1]
QI148.MaxTime =[23,58,0,-1]
QI148.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI148.Color =0
QI148.Item =[525,-1,-1,-1]
QI148.ItemCount =[12,-1,-1,-1]
QI148.ItemProbability =[20,-1,-1,-1]
QI148.Repeat =3
QI148.RewardMoney =6000
QR148.QuestID =148
QR148.EXP =0

# 149
QI149.QuestID =149
QI149.QuestSort =5
QI149.MinLevel =102
QI149.MaxLevel =112
QI149.RequiredFaction =0
QI149.MinTime =[0,1,0,-1]
QI149.MaxTime =[23,58,0,-1]
QI149.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI149.Color =0
QI149.Item =[526,-1,-1,-1]
QI149.ItemCount =[12,-1,-1,-1]
QI149.ItemProbability =[20,-1,-1,-1]
QI149.Repeat =3
QI149.RewardMoney =8000
QR149.QuestID =149
QR149.EXP =0

# 150
QI150.QuestID =150
QI150.QuestSort =5
QI150.MinLevel =50
QI150.MaxLevel =80
QI150.RequiredFaction =0
QI150.MinTime =[0,1,0,-1]
QI150.MaxTime =[23,58,0,-1]
QI150.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI150.Color =0
QI150.Repeat =3
QI150.RewardMoney =1000
QR150.QuestID =150
QR150.EXP =0

# 151
QI151.QuestID =151
QI151.QuestSort =1
QI151.MinLevel =2
QI151.MaxLevel =6
QI151.RequiredFaction =0
QI151.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI151.Color =0
QI151.Item =[527,-1,-1,-1]
QI151.ItemCount =[10,-1,-1,-1]
QI151.ItemProbability =[80,-1,-1,-1]
QI151.Repeat =0
QI151.RewardMoney =200
QR151.QuestID =151
QR151.EXP =250

# 152
QI152.QuestID =152
QI152.QuestSort =1
QI152.MinLevel =4
QI152.MaxLevel =10
QI152.RequiredFaction =0
QI152.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI152.Color =0
QI152.Item =[528,-1,-1,-1]
QI152.ItemCount =[8,-1,-1,-1]
QI152.ItemProbability =[60,-1,-1,-1]
QI152.Repeat =0
QI152.RewardMoney =300
QR152.QuestID =152
QR152.EXP =280

# 153
QI153.QuestID =153
QI153.QuestSort =1
QI153.MinLevel =8
QI153.MaxLevel =16
QI153.RequiredFaction =0
QI153.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI153.Color =0
QI153.Item =[529,-1,-1,-1]
QI153.ItemCount =[5,-1,-1,-1]
QI153.ItemProbability =[50,-1,-1,-1]
QI153.Repeat =0
QI153.RewardMoney =400
QR153.QuestID =153
QR153.EXP =350

# 154
QI154.QuestID =154
QI154.QuestSort =1
QI154.MinLevel =12
QI154.MaxLevel =20
QI154.RequiredFaction =0
QI154.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI154.Color =0
QI154.Creature =[1029,-1,-1,-1]
QI154.CreatureCount =[20,-1,-1,-1]
QI154.Repeat =0
QR154.QuestID =154
QR154.EXP =750

# 155
QI155.QuestID =155
QI155.QuestSort =1
QI155.MinLevel =20
QI155.MaxLevel =30
QI155.RequiredFaction =0
QI155.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI155.Color =0
QI155.Creature =[1047,-1,-1,-1]
QI155.CreatureCount =[25,-1,-1,-1]
QI155.Repeat =0
QR155.QuestID =155
QR155.EXP =1700

# 156
QI156.QuestID =156
QI156.QuestSort =1
QI156.MinLevel =30
QI156.MaxLevel =44
QI156.RequiredFaction =0
QI156.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI156.Color =0
QI156.Creature =[1046,-1,-1,-1]
QI156.CreatureCount =[40,-1,-1,-1]
QI156.Repeat =0
QR156.QuestID =156
QR156.EXP =3200
QR156.SkillPoint =1

# 157
QI157.QuestID =157
QI157.QuestSort =1
QI157.MinLevel =38
QI157.MaxLevel =52
QI157.RequiredFaction =0
QI157.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI157.Color =0
QI157.Item =[530,-1,-1,-1]
QI157.ItemCount =[10,-1,-1,-1]
QI157.ItemProbability =[20,-1,-1,-1]
QI157.Repeat =0
QR157.QuestID =157
QR157.EXP =5000
QR157.SkillPoint =1

# 158
QI158.QuestID =158
QI158.QuestSort =1
QI158.MinLevel =46
QI158.MaxLevel =56
QI158.RequiredFaction =0
QI158.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI158.Color =0
QI158.Creature =[1060,-1,-1,-1]
QI158.CreatureCount =[80,-1,-1,-1]
QI158.Repeat =0
QR158.QuestID =158
QR158.EXP =9000
QR158.SkillPoint =2

# 159
QI159.QuestID =159
QI159.QuestSort =1
QI159.MinLevel =50
QI159.MaxLevel =60
QI159.RequiredFaction =0
QI159.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI159.Color =0
QI159.Creature =[1062,-1,-1,-1]
QI159.CreatureCount =[100,-1,-1,-1]
QI159.Repeat =0
QR159.QuestID =159
QR159.EXP =12000
QR159.SkillPoint =3

# 160
QI160.QuestID =160
QI160.QuestSort =1
QI160.MinLevel =54
QI160.MaxLevel =66
QI160.RequiredFaction =0
QI160.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI160.Color =0
QI160.Creature =[1064,-1,-1,-1]
QI160.CreatureCount =[120,-1,-1,-1]
QI160.Repeat =0
QR160.QuestID =160
QR160.EXP =15000
QR160.SkillPoint =3

# 161
QI161.QuestID =161
QI161.QuestSort =1
QI161.MinLevel =68
QI161.MaxLevel =84
QI161.RequiredFaction =0
QI161.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI161.Color =0
QI161.Creature =[1081,-1,-1,-1]
QI161.CreatureCount =[120,-1,-1,-1]
QI161.Repeat =0
QR161.QuestID =161
QR161.EXP =19000
QR161.SkillPoint =3

# 162
QI162.QuestID =162
QI162.QuestSort =1
QI162.MinLevel =70
QI162.MaxLevel =86
QI162.RequiredFaction =0
QI162.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI162.Color =0
QI162.Item =[531,-1,-1,-1]
QI162.ItemCount =[12,-1,-1,-1]
QI162.ItemProbability =[10,-1,-1,-1]
QI162.Repeat =0
QR162.QuestID =162
QR162.EXP =20000
QR162.SkillPoint =3

# 163
QI163.QuestID =163
QI163.QuestSort =1
QI163.MinLevel =76
QI163.MaxLevel =90
QI163.RequiredFaction =0
QI163.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI163.Color =0
QI163.Creature =[1083,-1,-1,-1]
QI163.CreatureCount =[150,-1,-1,-1]
QI163.Repeat =0
QR163.QuestID =163
QR163.EXP =25000
QR163.SkillPoint =3

# 164
QI164.QuestID =164
QI164.QuestSort =1
QI164.MinLevel =80
QI164.MaxLevel =96
QI164.RequiredFaction =0
QI164.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI164.Color =0
QI164.Creature =[1084,-1,-1,-1]
QI164.CreatureCount =[150,-1,-1,-1]
QI164.Repeat =0
QR164.QuestID =164
QR164.EXP =28000
QR164.SkillPoint =3

# 165
QI165.QuestID =165
QI165.QuestSort =1
QI165.MinLevel =86
QI165.MaxLevel =100
QI165.RequiredFaction =0
QI165.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI165.Color =0
QI165.Creature =[1100,-1,-1,-1]
QI165.CreatureCount =[170,-1,-1,-1]
QI165.Repeat =0
QR165.QuestID =165
QR165.EXP =32000
QR165.SkillPoint =5

# 166
QI166.QuestID =166
QI166.QuestSort =1
QI166.MinLevel =90
QI166.MaxLevel =110
QI166.RequiredFaction =0
QI166.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI166.Color =0
QI166.Creature =[1102,-1,-1,-1]
QI166.CreatureCount =[180,-1,-1,-1]
QI166.Repeat =0
QR166.QuestID =166
QR166.EXP =38000
QR166.SkillPoint =5

# 167
QI167.QuestID =167
QI167.QuestSort =5
QI167.MinLevel =94
QI167.MaxLevel =112
QI167.RequiredFaction =0
QI167.MinTime =[0,1,0,-1]
QI167.MaxTime =[23,58,0,-1]
QI167.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI167.Color =0
QI167.Creature =[1091,-1,-1,-1]
QI167.CreatureCount =[100,-1,-1,-1]
QI167.Repeat =3
QI167.RewardItem[0].Base =4231
QI167.RewardItem[0].Overlap =1
QI167.RewardItem[0].Binding =1
QR167.QuestID =167
QR167.EXP =40000
QR167.SkillPoint =6

# 168
QI168.QuestID =168
QI168.QuestSort =5
QI168.MinLevel =100
QI168.MaxLevel =116
QI168.RequiredFaction =0
QI168.MinTime =[0,1,0,-1]
QI168.MaxTime =[23,58,0,-1]
QI168.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI168.Color =0
QI168.Creature =[1094,-1,-1,-1]
QI168.CreatureCount =[100,-1,-1,-1]
QI168.Repeat =3
QI168.RewardItem[0].Base =4221
QI168.RewardItem[0].Overlap =1
QI168.RewardItem[0].Binding =1
QR168.QuestID =168
QR168.EXP =45000
QR168.SkillPoint =6

# 169
QI169.QuestID =169
QI169.QuestSort =5
QI169.MinLevel =106
QI169.MaxLevel =120
QI169.RequiredFaction =0
QI169.MinTime =[0,1,0,-1]
QI169.MaxTime =[23,58,0,-1]
QI169.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI169.Color =1
QI169.Creature =[1117,-1,-1,-1]
QI169.CreatureCount =[100,-1,-1,-1]
QI169.Repeat =3
QI169.RewardItem[0].Base =4211
QI169.RewardItem[0].Overlap =1
QI169.RewardItem[0].Binding =1
QR169.QuestID =169
QR169.EXP =55000
QR169.SkillPoint =8

# 170
QI170.QuestID =170
QI170.QuestSort =5
QI170.MinLevel =110
QI170.MaxLevel =120
QI170.RequiredFaction =0
QI170.MinTime =[0,1,0,-1]
QI170.MaxTime =[23,58,0,-1]
QI170.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI170.Color =2
QI170.Creature =[1075,-1,-1,-1]
QI170.CreatureCount =[200,-1,-1,-1]
QI170.Repeat =3
QI170.RewardItem[0].Base =4200
QI170.RewardItem[0].Overlap =1
QI170.RewardItem[0].Binding =1
QR170.QuestID =170
QR170.EXP =100000
QR170.SkillPoint =16

# 171
QI171.QuestID =171
QI171.QuestSort =4
QI171.MinLevel =50
QI171.RequiredFaction =0
QI171.MinTime =[0,1,0,-1]
QI171.MaxTime =[23,58,0,-1]
QI171.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI171.Color =1
QI171.Repeat =1
QI171.RewardItem[0].Base =4230
QI171.RewardItem[0].Overlap =1
QI171.RewardItem[0].Binding =1
QR171.QuestID =171
QR171.EXP =25000
QR171.SkillPoint =5

# 172
QI172.QuestID =172
QI172.QuestSort =5
QI172.MinLevel =48
QI172.MaxLevel =70
QI172.RequiredFaction =0
QI172.MinTime =[0,1,0,-1]
QI172.MaxTime =[23,58,0,-1]
QI172.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI172.Color =1
QI172.Creature =[1110,-1,-1,-1]
QI172.CreatureCount =[30,-1,-1,-1]
QI172.Repeat =3
QR172.QuestID =172
QR172.EXP =18000

# 173
QI173.QuestID =173
QI173.QuestSort =5
QI173.MinLevel =64
QI173.MaxLevel =80
QI173.RequiredFaction =0
QI173.MinTime =[0,1,0,-1]
QI173.MaxTime =[23,58,0,-1]
QI173.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI173.Color =1
QI173.Creature =[1111,-1,-1,-1]
QI173.CreatureCount =[40,-1,-1,-1]
QI173.Repeat =3
QR173.QuestID =173
QR173.EXP =30000

# 174
QI174.QuestID =174
QI174.QuestSort =5
QI174.MinLevel =74
QI174.MaxLevel =92
QI174.RequiredFaction =0
QI174.MinTime =[0,1,0,-1]
QI174.MaxTime =[23,58,0,-1]
QI174.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI174.Color =1
QI174.Creature =[1112,-1,-1,-1]
QI174.CreatureCount =[50,-1,-1,-1]
QI174.Repeat =3
QR174.QuestID =174
QR174.EXP =46000

# 175
QI175.QuestID =175
QI175.QuestSort =5
QI175.MinLevel =82
QI175.MaxLevel =100
QI175.RequiredFaction =0
QI175.MinTime =[0,1,0,-1]
QI175.MaxTime =[23,58,0,-1]
QI175.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI175.Color =2
QI175.Creature =[1113,-1,-1,-1]
QI175.CreatureCount =[50,-1,-1,-1]
QI175.Repeat =3
QR175.QuestID =175
QR175.EXP =57000

# 176
QI176.QuestID =176
QI176.QuestSort =5
QI176.MinLevel =88
QI176.MaxLevel =108
QI176.RequiredFaction =0
QI176.MinTime =[0,1,0,-1]
QI176.MaxTime =[23,58,0,-1]
QI176.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI176.Color =2
QI176.Creature =[1114,-1,-1,-1]
QI176.CreatureCount =[50,-1,-1,-1]
QI176.Repeat =3
QR176.QuestID =176
QR176.EXP =68000

# 177
QI177.QuestID =177
QI177.QuestSort =5
QI177.MinLevel =96
QI177.MaxLevel =118
QI177.RequiredFaction =0
QI177.MinTime =[0,1,0,-1]
QI177.MaxTime =[23,58,0,-1]
QI177.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI177.Color =2
QI177.Creature =[1115,-1,-1,-1]
QI177.CreatureCount =[50,-1,-1,-1]
QI177.Repeat =3
QR177.QuestID =177
QR177.EXP =80000

# 178
QI178.QuestID =178
QI178.QuestSort =5
QI178.MinLevel =104
QI178.MaxLevel =120
QI178.RequiredFaction =0
QI178.MinTime =[0,1,0,-1]
QI178.MaxTime =[23,58,0,-1]
QI178.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI178.Color =3
QI178.Creature =[1119,-1,-1,-1]
QI178.CreatureCount =[10,-1,-1,-1]
QI178.Repeat =3
QI178.RewardItem[0].Base =4230
QI178.RewardItem[0].Overlap =3
QI178.RewardItem[0].Binding =1
QI178.RewardItem[1].Base =4220
QI178.RewardItem[1].Overlap =2
QI178.RewardItem[1].Binding =1
QI178.RewardItem[2].Base =4210
QI178.RewardItem[2].Overlap =2
QI178.RewardItem[2].Binding =1
QR178.QuestID =178
QR178.EXP =120000

# 179
QI179.QuestID =179
QI179.QuestSort =4
QI179.MinLevel =90
QI179.MaxLevel =110
QI179.RequiredFaction =0
QI179.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI179.Color =1
QI179.Creature =[1077,-1,-1,-1]
QI179.CreatureCount =[50,-1,-1,-1]
QI179.Repeat =0
QR179.QuestID =179
QR179.EXP =40000
QR179.SkillPoint =6

# 180
QI180.QuestID =180
QI180.QuestSort =4
QI180.MinLevel =100
QI180.MaxLevel =120
QI180.RequiredFaction =0
QI180.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI180.Color =1
QI180.Creature =[1078,-1,-1,-1]
QI180.CreatureCount =[50,-1,-1,-1]
QI180.Repeat =0
QR180.QuestID =180
QR180.EXP =55000
QR180.SkillPoint =8

# 181
QI181.QuestID =181
QI181.QuestSort =1
QI181.MinLevel =38
QI181.MaxLevel =48
QI181.RequiredFaction =0
QI181.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI181.Color =0
QI181.Creature =[1042,-1,-1,-1]
QI181.CreatureCount =[50,-1,-1,-1]
QI181.Repeat =0
QR181.QuestID =181
QR181.EXP =4500
QR181.SkillPoint =1

# 182
QI182.QuestID =182
QI182.QuestSort =1
QI182.MinLevel =60
QI182.MaxLevel =76
QI182.RequiredFaction =0
QI182.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI182.Color =0
QI182.Creature =[1067,-1,-1,-1]
QI182.CreatureCount =[120,-1,-1,-1]
QI182.Repeat =0
QR182.QuestID =182
QR182.EXP =17000
QR182.SkillPoint =3

# 183
QI183.QuestID =183
QI183.QuestSort =6
QI183.PrevQuestId =-1
QI183.NextQuestId =184
QI183.MinLevel =3
QI183.RequiredFaction =0
QI183.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI183.Color =1
QI183.Repeat =3
QR183.QuestID =183
QR183.EXP =100

# 184
QI184.QuestID =184
QI184.QuestSort =6
QI184.PrevQuestId =183
QI184.NextQuestId =185
QI184.MinLevel =3
QI184.RequiredFaction =0
QI184.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI184.Color =1
QI184.Repeat =3
QR184.QuestID =184
QR184.EXP =100

# 185
QI185.QuestID =185
QI185.QuestSort =6
QI185.PrevQuestId =184
QI185.NextQuestId =183
QI185.MinLevel =3
QI185.RequiredFaction =0
QI185.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_LOOP
QI185.Color =1
QI185.Creature =[1027,-1,-1,-1]
QI185.CreatureCount =[1,-1,-1,-1]
QI185.Repeat =3
QI185.RewardMoney =100
QR185.QuestID =185
QR185.EXP =1000

# 186
QI186.QuestID =186
QI186.QuestSort =7
QI186.MinLevel =3
QI186.RequiredFaction =0
QI186.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI186.Color =1
QI186.Repeat =1
QR186.QuestID =186
QR186.EXP =100

# 187
QI187.QuestID =187
QI187.QuestSort =7
QI187.MinLevel =3
QI187.RequiredFaction =0
QI187.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI187.Color =1
QI187.Creature =[1028,-1,-1,-1]
QI187.CreatureCount =[1,-1,-1,-1]
QI187.Repeat =1
QI187.RewardMoney =100
QR187.QuestID =187
QR187.EXP =1000

# 207
QI207.QuestID =207
QI207.QuestSort =8
QI207.MinLevel =3
QI207.MaxLevel =17
QI207.RequiredFaction =0
QI207.MinTime =[0,1,0,-1]
QI207.MaxTime =[23,58,0,-1]
QI207.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI207.Color =0
QI207.Repeat =3
QI207.RewardUionMoney =5
QR207.QuestID =207
QR207.EXP =0
QR207.UionContribute =1

# 208
QI208.QuestID =208
QI208.QuestSort =8
QI208.MinLevel =18
QI208.MaxLevel =32
QI208.RequiredFaction =0
QI208.MinTime =[0,1,0,-1]
QI208.MaxTime =[23,58,0,-1]
QI208.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI208.Color =0
QI208.Repeat =3
QI208.RewardUionMoney =5
QR208.QuestID =208
QR208.EXP =0
QR208.UionContribute =1

# 209
QI209.QuestID =209
QI209.QuestSort =8
QI209.MinLevel =33
QI209.MaxLevel =47
QI209.RequiredFaction =0
QI209.MinTime =[0,1,0,-1]
QI209.MaxTime =[23,58,0,-1]
QI209.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI209.Color =0
QI209.Repeat =3
QI209.RewardUionMoney =5
QR209.QuestID =209
QR209.EXP =0
QR209.UionContribute =1

# 223
QI223.QuestID =223
QI223.QuestSort =8
QI223.MinLevel =48
QI223.MaxLevel =62
QI223.RequiredFaction =0
QI223.MinTime =[0,1,0,-1]
QI223.MaxTime =[23,58,0,-1]
QI223.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI223.Color =0
QI223.Repeat =3
QI223.RewardUionMoney =6
QR223.QuestID =223
QR223.EXP =0
QR223.UionContribute =1

# 224
QI224.QuestID =224
QI224.QuestSort =8
QI224.MinLevel =63
QI224.MaxLevel =77
QI224.RequiredFaction =0
QI224.MinTime =[0,1,0,-1]
QI224.MaxTime =[23,58,0,-1]
QI224.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI224.Color =0
QI224.Repeat =3
QI224.RewardUionMoney =6
QR224.QuestID =224
QR224.EXP =0
QR224.UionContribute =1

# 225
QI225.QuestID =225
QI225.QuestSort =8
QI225.MinLevel =78
QI225.MaxLevel =92
QI225.RequiredFaction =0
QI225.MinTime =[0,1,0,-1]
QI225.MaxTime =[23,58,0,-1]
QI225.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI225.Color =0
QI225.Repeat =3
QI225.RewardUionMoney =6
QR225.QuestID =225
QR225.EXP =0
QR225.UionContribute =1

# 226
QI226.QuestID =226
QI226.QuestSort =8
QI226.MinLevel =93
QI226.MaxLevel =107
QI226.RequiredFaction =0
QI226.MinTime =[0,1,0,-1]
QI226.MaxTime =[23,58,0,-1]
QI226.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_TIMED
QI226.Color =0
QI226.Repeat =3
QI226.RewardUionMoney =6
QR226.QuestID =226
QR226.EXP =0
QR226.UionContribute =2

# 210
QI210.QuestID =210
QI210.QuestSort =8
QI210.MinLevel =14
QI210.MaxLevel =28
QI210.RequiredFaction =0
QI210.MinTime =[0,1,0,-1]
QI210.MaxTime =[23,58,0,-1]
QI210.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI210.Color =0
QI210.Creature =[1024,-1,-1,-1]
QI210.CreatureCount =[100,-1,-1,-1]
QI210.Repeat =3
QI210.RewardUionBijou =1
QI210.RewardUionMoney =10
QR210.QuestID =210
QR210.EXP =0
QR210.UionContribute =2

# 211
QI211.QuestID =211
QI211.QuestSort =8
QI211.MinLevel =29
QI211.MaxLevel =43
QI211.RequiredFaction =0
QI211.MinTime =[0,1,0,-1]
QI211.MaxTime =[23,58,0,-1]
QI211.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI211.Color =0
QI211.Creature =[1040,-1,-1,-1]
QI211.CreatureCount =[100,-1,-1,-1]
QI211.Repeat =3
QI211.RewardUionBijou =1
QI211.RewardUionMoney =12
QR211.QuestID =211
QR211.EXP =0
QR211.UionContribute =2

# 212
QI212.QuestID =212
QI212.QuestSort =8
QI212.MinLevel =44
QI212.MaxLevel =58
QI212.RequiredFaction =0
QI212.MinTime =[0,1,0,-1]
QI212.MaxTime =[23,58,0,-1]
QI212.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI212.Color =0
QI212.Creature =[1045,-1,-1,-1]
QI212.CreatureCount =[100,-1,-1,-1]
QI212.Repeat =3
QI212.RewardUionBijou =1
QI212.RewardUionMoney =15
QR212.QuestID =212
QR212.EXP =0
QR212.UionContribute =2

# 227
QI227.QuestID =227
QI227.QuestSort =8
QI227.MinLevel =59
QI227.MaxLevel =73
QI227.RequiredFaction =0
QI227.MinTime =[0,1,0,-1]
QI227.MaxTime =[23,58,0,-1]
QI227.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI227.Color =0
QI227.Creature =[1066,-1,-1,-1]
QI227.CreatureCount =[100,-1,-1,-1]
QI227.Repeat =3
QI227.RewardUionBijou =1
QI227.RewardUionMoney =19
QR227.QuestID =227
QR227.EXP =0
QR227.UionContribute =3

# 228
QI228.QuestID =228
QI228.QuestSort =8
QI228.MinLevel =74
QI228.MaxLevel =88
QI228.RequiredFaction =0
QI228.MinTime =[0,1,0,-1]
QI228.MaxTime =[23,58,0,-1]
QI228.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI228.Color =0
QI228.Creature =[1082,-1,-1,-1]
QI228.CreatureCount =[100,-1,-1,-1]
QI228.Repeat =3
QI228.RewardUionBijou =1
QI228.RewardUionMoney =24
QR228.QuestID =228
QR228.EXP =0
QR228.UionContribute =3

# 229
QI229.QuestID =229
QI229.QuestSort =8
QI229.MinLevel =89
QI229.MaxLevel =103
QI229.RequiredFaction =0
QI229.MinTime =[0,1,0,-1]
QI229.MaxTime =[23,58,0,-1]
QI229.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI229.Color =0
QI229.Creature =[1101,-1,-1,-1]
QI229.CreatureCount =[100,-1,-1,-1]
QI229.Repeat =3
QI229.RewardUionBijou =1
QI229.RewardUionMoney =30
QR229.QuestID =229
QR229.EXP =0
QR229.UionContribute =3

# 230
QI230.QuestID =230
QI230.QuestSort =8
QI230.MinLevel =104
QI230.MaxLevel =118
QI230.RequiredFaction =0
QI230.MinTime =[0,1,0,-1]
QI230.MaxTime =[23,58,0,-1]
QI230.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_TIMED
QI230.Color =0
QI230.Creature =[1106,-1,-1,-1]
QI230.CreatureCount =[100,-1,-1,-1]
QI230.Repeat =3
QI230.RewardUionBijou =1
QI230.RewardUionMoney =36
QR230.QuestID =230
QR230.EXP =0
QR230.UionContribute =3

# 188
QI188.QuestID =188
QI188.QuestSort =4
QI188.MinLevel =200
QI188.RequiredFaction =0
QI188.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI188.Color =0
QI188.ExplorerMapID =4
QI188.ExplorerMapPosition =-177,-25
QI188.RewardMoney =200
QR188.QuestID =188
QR188.EXP =200

# 189
QI189.QuestID =189
QI189.QuestSort =4
QI189.MinLevel =200
QI189.RequiredFaction =0
QI189.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI189.Color =0
QI189.ExplorerMapID =0,0
QI189.ExplorerMapPosition =7,-13,-107,-135
QI189.RewardMoney =500
QR189.QuestID =189
QR189.EXP =500

# 190
QI190.QuestID =190
QI190.QuestSort =1
QI190.MinLevel =15
QI190.MaxLevel =27
QI190.RequiredFaction =0
QI190.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI190.Color =0
QI190.Creature =[1024,-1,-1,-1]
QI190.CreatureCount =[20,-1,-1,-1]
QI190.Repeat =0
QR190.QuestID =190
QR190.EXP =800

# 191
QI191.QuestID =191
QI191.QuestSort =1
QI191.MinLevel =20
QI191.MaxLevel =32
QI191.RequiredFaction =0
QI191.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI191.Color =0
QI191.Creature =[1025,-1,-1,-1]
QI191.CreatureCount =[25,-1,-1,-1]
QI191.Repeat =0
QR191.QuestID =191
QR191.EXP =1600

# 197
QI197.QuestID =197
QI197.QuestSort =1
QI197.MinLevel =25
QI197.MaxLevel =37
QI197.RequiredFaction =0
QI197.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI197.Color =0
QI197.Creature =[1048,-1,-1,-1]
QI197.CreatureCount =[30,-1,-1,-1]
QI197.Repeat =0
QR197.QuestID =197
QR197.EXP =2200
QR197.SkillPoint =1

# 198
QI198.QuestID =198
QI198.QuestSort =1
QI198.MinLevel =30
QI198.MaxLevel =42
QI198.RequiredFaction =0
QI198.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI198.Color =0
QI198.Creature =[1046,-1,-1,-1]
QI198.CreatureCount =[35,-1,-1,-1]
QI198.Repeat =0
QR198.QuestID =198
QR198.EXP =2900
QR198.SkillPoint =1

# 199
QI199.QuestID =199
QI199.QuestSort =1
QI199.MinLevel =40
QI199.MaxLevel =52
QI199.RequiredFaction =0
QI199.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI199.Color =0
QI199.Creature =[1043,-1,-1,-1]
QI199.CreatureCount =[40,-1,-1,-1]
QI199.Repeat =0
QR199.QuestID =199
QR199.EXP =4000
QR199.SkillPoint =1

# 192
QI192.QuestID =192
QI192.QuestSort =4
QI192.MinLevel =12
QI192.MaxLevel =20
QI192.RequiredFaction =0
QI192.TeamLimit =1
QI192.MinTime =[0,1,0,-1]
QI192.MaxTime =[23,58,0,-1]
QI192.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI192.Color =1
QI192.Creature =[1029,-1,-1,-1]
QI192.CreatureCount =[50,-1,-1,-1]
QI192.Repeat =1
QR192.QuestID =192
QR192.EXP =5000
QR192.SkillPoint =4

# 193
QI193.QuestID =193
QI193.QuestSort =4
QI193.MinLevel =21
QI193.MaxLevel =28
QI193.RequiredFaction =0
QI193.TeamLimit =2
QI193.MinTime =[0,1,0,-1]
QI193.MaxTime =[23,58,0,-1]
QI193.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI193.Color =2
QI193.Creature =[1026,-1,-1,-1]
QI193.CreatureCount =[1,-1,-1,-1]
QI193.Repeat =1
QR193.QuestID =193
QR193.EXP =15000
QR193.SkillPoint =6

# 194
QI194.QuestID =194
QI194.QuestSort =4
QI194.MinLevel =30
QI194.MaxLevel =40
QI194.RequiredFaction =0
QI194.TeamLimit =3
QI194.MinTime =[0,1,0,-1]
QI194.MaxTime =[23,58,0,-1]
QI194.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI194.Color =2
QI194.Creature =[1048,-1,-1,-1]
QI194.CreatureCount =[100,-1,-1,-1]
QI194.Repeat =1
QR194.QuestID =194
QR194.EXP =15000
QR194.SkillPoint =6

# 195
QI195.QuestID =195
QI195.QuestSort =4
QI195.MinLevel =20
QI195.MaxLevel =50
QI195.RequiredFaction =0
QI195.TeamLimit =1
QI195.MinTime =[0,1,0,-1]
QI195.MaxTime =[23,58,0,-1]
QI195.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO+QUEST_SPECIAL_FLAGS_REPEATABLE+QUEST_SPECIAL_FLAGS_TIMED
QI195.Color =0
QI195.Repeat =1
QR195.QuestID =195
QR195.EXP =1000

# 196
QI196.QuestID =196
QI196.QuestSort =4

# 200
QI200.QuestID =200
QI200.QuestSort =1
QI200.MinLevel =50
QI200.MaxLevel =62
QI200.RequiredFaction =0
QI200.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI200.Color =0
QI200.Creature =[1062,-1,-1,-1]
QI200.CreatureCount =[50,-1,-1,-1]
QI200.Repeat =0
QR200.QuestID =200
QR200.EXP =6000
QR200.SkillPoint =1

# 201
QI201.QuestID =201
QI201.QuestSort =1
QI201.MinLevel =60
QI201.MaxLevel =72
QI201.RequiredFaction =0
QI201.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI201.Color =0
QI201.Creature =[1066,-1,-1,-1]
QI201.CreatureCount =[60,-1,-1,-1]
QI201.Repeat =0
QR201.QuestID =201
QR201.EXP =8200
QR201.SkillPoint =1

# 202
QI202.QuestID =202
QI202.QuestSort =1
QI202.MinLevel =70
QI202.MaxLevel =80
QI202.RequiredFaction =0
QI202.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI202.Color =0
QI202.Creature =[1081,-1,-1,-1]
QI202.CreatureCount =[70,-1,-1,-1]
QI202.Repeat =0
QR202.QuestID =202
QR202.EXP =11000
QR202.SkillPoint =1

# 203
QI203.QuestID =203
QI203.QuestSort =1
QI203.MinLevel =81
QI203.MaxLevel =90
QI203.RequiredFaction =0
QI203.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI203.Color =0
QI203.Creature =[1084,-1,-1,-1]
QI203.CreatureCount =[80,-1,-1,-1]
QI203.Repeat =0
QR203.QuestID =203
QR203.EXP =14000
QR203.SkillPoint =2

# 204
QI204.QuestID =204
QI204.QuestSort =1
QI204.MinLevel =91
QI204.MaxLevel =100
QI204.RequiredFaction =0
QI204.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI204.Color =0
QI204.Creature =[1115,-1,-1,-1]
QI204.CreatureCount =[90,-1,-1,-1]
QI204.Repeat =0
QR204.QuestID =204
QR204.EXP =18000
QR204.SkillPoint =2

# 205
QI205.QuestID =205
QI205.QuestSort =1
QI205.MinLevel =101
QI205.MaxLevel =111
QI205.RequiredFaction =0
QI205.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI205.Color =0
QI205.Creature =[1117,-1,-1,-1]
QI205.CreatureCount =[100,-1,-1,-1]
QI205.Repeat =0
QR205.QuestID =205
QR205.EXP =28000
QR205.SkillPoint =4

# 206
QI206.QuestID =206
QI206.QuestSort =1
QI206.MinLevel =111
QI206.MaxLevel =119
QI206.RequiredFaction =0
QI206.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST+QUEST_SPECIAL_FLAGS_REPEATABLE
QI206.Color =0
QI206.Creature =[1106,-1,-1,-1]
QI206.CreatureCount =[100,-1,-1,-1]
QI206.Repeat =0
QR206.QuestID =206
QR206.EXP =32000
QR206.SkillPoint =4

# 213
QI213.QuestID =213
QI213.QuestSort =4
QI213.MinLevel =200
QI213.RequiredFaction =0
QI213.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI213.Color =0
QI213.ExplorerMapID =0
QI213.ExplorerMapPosition =136,116
QI213.RewardMoney =1000
QR213.QuestID =213
QR213.EXP =2000

# 214
QI214.QuestID =214
QI214.QuestSort =4
QI214.MinLevel =200
QI214.RequiredFaction =0
QI214.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI214.Color =0
QI214.ExplorerMapID =0
QI214.ExplorerMapPosition =48,-50
QI214.RewardMoney =2000
QR214.QuestID =214
QR214.EXP =4000

# 215
QI215.QuestID =215
QI215.QuestSort =4
QI215.MinLevel =200
QI215.RequiredFaction =0
QI215.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI215.Color =0
QI215.ExplorerMapID =13
QI215.ExplorerMapPosition =46,-204
QI215.RewardMoney =2700
QR215.QuestID =215
QR215.EXP =5400

# 216
QI216.QuestID =216
QI216.QuestSort =4
QI216.MinLevel =200
QI216.RequiredFaction =0
QI216.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI216.Color =0
QI216.ExplorerMapID =5
QI216.ExplorerMapPosition =-36,57
QI216.RewardMoney =3200
QR216.QuestID =216
QR216.EXP =6400

# 217
QI217.QuestID =217
QI217.QuestSort =2
QI217.NextQuestsId =218,-1
QI217.MinLevel =70
QI217.RequiredFaction =0
QI217.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI217.Color =1
QI217.Creature =[9061,-1,-1,-1]
QI217.CreatureCount =[1,-1,-1,-1]
QI217.Repeat =1
QI217.RewardMoney =20000
QR217.QuestID =217
QR217.EXP =10000
QR217.SkillPoint =1

# 218
QI218.QuestID =218
QI218.QuestSort =2
QI218.PrevQuestId =217
QI218.NextQuestsId =219,-1
QI218.MinLevel =70
QI218.RequiredFaction =0
QI218.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI218.Color =1
QI218.Repeat =1
QI218.RewardMoney =1000
QR218.QuestID =218
QR218.EXP =3000

# 219
QI219.QuestID =219
QI219.QuestSort =4
QI219.PrevQuestId =218
QI219.NextQuestsId =220,-1
QI219.MinLevel =200
QI219.RequiredFaction =0
QI219.SpecialFlags =QUEST_SPECIAL_FLAGS_MAP_EXPLORER
QI219.Color =1
QI219.ExplorerMapID =16
QI219.ExplorerMapPosition =50,0
QI219.RewardMoney =2000
QR219.QuestID =219
QR219.EXP =5000

# 220
QI220.QuestID =220
QI220.QuestSort =2
QI220.PrevQuestId =219
QI220.NextQuestsId =221,-1
QI220.MinLevel =75
QI220.RequiredFaction =0
QI220.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI220.Color =1
QI220.Creature =[9064,-1,-1,-1]
QI220.CreatureCount =[1,-1,-1,-1]
QI220.Repeat =1
QI220.RewardMoney =20000
QR220.QuestID =220
QR220.EXP =12000
QR220.SkillPoint =2

# 221
QI221.QuestID =221
QI221.QuestSort =2
QI221.PrevQuestId =220
QI221.NextQuestsId =222,-1
QI221.MinLevel =90
QI221.RequiredFaction =0
QI221.SpecialFlags =QUEST_SPECIAL_FLAGS_KILL_OR_CAST
QI221.Color =1
QI221.Creature =[1086,-1,-1,-1]
QI221.CreatureCount =[1,-1,-1,-1]
QI221.Repeat =1
QI221.RewardMoney =30000
QR221.QuestID =221
QR221.EXP =40000
QR221.SkillPoint =3

# 222
QI222.QuestID =222
QI222.QuestSort =2
QI222.PrevQuestId =221
QI222.MinLevel =90
QI222.RequiredFaction =0
QI222.SpecialFlags =QUEST_SPECIAL_FLAGS_SPEAKTO
QI222.Color =1
QI222.Repeat =1
QI222.RewardMoney =0
QR222.QuestID =222
QR222.EXP =10000
QR222.SkillPoint =1

