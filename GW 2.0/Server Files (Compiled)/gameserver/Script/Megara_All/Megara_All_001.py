import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1082 , Script.Quest.QI1161 , Script.Quest.QI1164

def GetQuestReward():
  return Script.Quest.QR1081 , Script.Quest.QR1161 , Script.Quest.QR1164


def Talk( player ):
# print "talk to Megara_All_001"
  return "Megara_All_001"

