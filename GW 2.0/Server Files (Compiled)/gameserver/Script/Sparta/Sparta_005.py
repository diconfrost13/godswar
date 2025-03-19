import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI23 , Script.Quest.QI25 , Script.Quest.QI26

def GetQuestReward():
  return Script.Quest.QR22 , Script.Quest.QR24 , Script.Quest.QR25


def Talk( player ):
# print "talk to Sparta_005"
  return "Sparta_005"

