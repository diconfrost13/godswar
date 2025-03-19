import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI32 , Script.Quest.QI33 , Script.Quest.QI41 , Script.Quest.QI42 , Script.Quest.QI46

def GetQuestReward():
  return Script.Quest.QR31 , Script.Quest.QR32 , Script.Quest.QR40 , Script.Quest.QR41 , Script.Quest.QR45


def Talk( player ):
# print "talk to Sparta_008"
  return "Sparta_008"

