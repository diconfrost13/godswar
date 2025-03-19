import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI55 , Script.Quest.QI58

def GetQuestReward():
  return Script.Quest.QR54 , Script.Quest.QR57


def Talk( player ):
# print "talk to Sparta_Newbie_006"
  return "Sparta_Newbie_006"

