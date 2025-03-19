import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_BANKER)

def GetQuest():
  return Script.Quest.QI1010 , Script.Quest.QI1045

def GetQuestReward():
  return Script.Quest.QR1009 , Script.Quest.QR1044


def Talk( player ):
# print "talk to Athens_Newbie_007"
  return "Athens_Newbie_007"

