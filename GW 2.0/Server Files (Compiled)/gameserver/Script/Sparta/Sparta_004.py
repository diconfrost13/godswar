import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI19 , Script.Quest.QI22

def GetQuestReward():
  return Script.Quest.QR18 , Script.Quest.QR21


def Talk( player ):
# print "talk to Sparta_004"
  return "Sparta_004"

