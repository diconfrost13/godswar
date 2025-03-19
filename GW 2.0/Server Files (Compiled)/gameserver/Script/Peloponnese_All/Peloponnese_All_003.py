import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI48 , Script.Quest.QI181 , Script.Quest.QI185

def GetQuestReward():
  return Script.Quest.QR47 , Script.Quest.QR181 , Script.Quest.QR184


def Talk( player ):
# print "talk to Peloponnese_All_003"
  return "Peloponnese_All_003"

