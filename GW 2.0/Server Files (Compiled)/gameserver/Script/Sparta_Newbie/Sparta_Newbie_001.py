import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI0 , Script.Quest.QI2 , Script.Quest.QI11

def GetQuestReward():
  return Script.Quest.QR1 , Script.Quest.QR10


def Talk( player ):
# print "talk to Sparta_Newbie_001"
  return "Sparta_Newbie_001"

