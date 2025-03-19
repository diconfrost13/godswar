import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI64 , Script.Quest.QI65

def GetQuestReward():
  return Script.Quest.QR63 , Script.Quest.QR64


def Talk( player ):
# print "talk to Peloponnese_All_006"
  return "Peloponnese_All_006"

