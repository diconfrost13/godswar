import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1000 , Script.Quest.QI1002 , Script.Quest.QI1011

def GetQuestReward():
  return Script.Quest.QR1001 , Script.Quest.QR1010


def Talk( player ):
# print "talk to Athens_Newbie_001"
  return "Athens_Newbie_001"

