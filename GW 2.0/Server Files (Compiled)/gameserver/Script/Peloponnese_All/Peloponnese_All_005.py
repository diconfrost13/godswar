import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI62 , Script.Quest.QI63 , Script.Quest.QI66

def GetQuestReward():
  return Script.Quest.QR61 , Script.Quest.QR62 , Script.Quest.QR65


def Talk( player ):
# print "talk to Peloponnese_All_005"
  return "Peloponnese_All_005"

