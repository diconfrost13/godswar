import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI128

def GetQuestReward():
  return Script.Quest.QR123 , Script.Quest.QR124 , Script.Quest.QR125 , Script.Quest.QR126 , Script.Quest.QR127 , Script.Quest.QR128


def Talk( player ):
# print "talk to Sparta_020"
  return "Sparta_020"

