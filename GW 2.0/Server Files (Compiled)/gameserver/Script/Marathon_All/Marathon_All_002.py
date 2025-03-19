import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1050 , Script.Quest.QI1053 , Script.Quest.QI1198 , Script.Quest.QI1199 , Script.Quest.QI1219 , Script.Quest.QI1220 , Script.Quest.QI1221 , Script.Quest.QI1222

def GetQuestReward():
  return Script.Quest.QR1049 , Script.Quest.QR1052 , Script.Quest.QR1198 , Script.Quest.QR1199 , Script.Quest.QR1217 , Script.Quest.QR1218 , Script.Quest.QR1219 , Script.Quest.QR1220 , Script.Quest.QR1221


def Talk( player ):
# print "talk to Marathon_All_002"
  return "Marathon_All_002"

