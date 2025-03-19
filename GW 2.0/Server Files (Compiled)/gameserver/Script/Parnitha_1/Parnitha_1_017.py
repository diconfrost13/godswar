import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1095 , Script.Quest.QI1096 , Script.Quest.QI1098

def GetQuestReward():
  return Script.Quest.QR1094 , Script.Quest.QR1095 , Script.Quest.QR1097


def Talk( player ):
# print "talk to Parnitha_1_017"
  return "Parnitha_1_017"

