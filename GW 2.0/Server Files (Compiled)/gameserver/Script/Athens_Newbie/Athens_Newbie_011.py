import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1055 , Script.Quest.QI1058

def GetQuestReward():
  return Script.Quest.QR1054 , Script.Quest.QR1057


def Talk( player ):
# print "talk to Athens_Newbie_011"
  return "Athens_Newbie_011"

