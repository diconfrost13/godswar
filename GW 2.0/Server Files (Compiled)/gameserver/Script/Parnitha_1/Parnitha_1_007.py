import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1100

def GetQuestReward():
  return Script.Quest.QR1099 , Script.Quest.QR1100 , Script.Quest.QR1142


def Talk( player ):
# print "talk to Parnitha_1_007"
  return "Parnitha_1_007"

