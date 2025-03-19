import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI68 , Script.Quest.QI109

def GetQuestReward():
  return Script.Quest.QR67 , Script.Quest.QR108 , Script.Quest.QR109


def Talk( player ):
# print "talk to Peloponnese_All_007"
  return "Peloponnese_All_007"

