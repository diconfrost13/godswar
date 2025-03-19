import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1035 , Script.Quest.QI1040 , Script.Quest.QI1044

def GetQuestReward():
  return Script.Quest.QR1034 , Script.Quest.QR1039 , Script.Quest.QR1043


def Talk( player ):
# print "talk to Athens_Newbie_010"
  return "Athens_Newbie_010"

