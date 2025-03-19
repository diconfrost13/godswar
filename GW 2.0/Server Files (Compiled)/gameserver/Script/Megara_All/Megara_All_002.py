import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1083 , Script.Quest.QI1084 , Script.Quest.QI1167 , Script.Quest.QI1168

def GetQuestReward():
  return Script.Quest.QR1082 , Script.Quest.QR1083 , Script.Quest.QR1139 , Script.Quest.QR1167 , Script.Quest.QR1168


def Talk( player ):
# print "talk to Megara_All_002"
  return "Megara_All_002"

