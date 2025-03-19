import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_BANKER)

def GetQuest():
  return Script.Quest.QI10 , Script.Quest.QI45

def GetQuestReward():
  return Script.Quest.QR9 , Script.Quest.QR44


def Talk( player ):
# print "talk to Sparta_Newbie_012"
  return "Sparta_Newbie_012"

