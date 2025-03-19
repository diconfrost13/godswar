import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI77 , Script.Quest.QI156

def GetQuestReward():
  return Script.Quest.QR76 , Script.Quest.QR156


def Talk( player ):
# print "talk to Peloponnese_All_008"
  return "Peloponnese_All_008"

