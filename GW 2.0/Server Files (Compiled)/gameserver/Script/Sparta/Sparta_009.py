import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI24 , Script.Quest.QI27 , Script.Quest.QI31 , Script.Quest.QI34 , Script.Quest.QI47 , Script.Quest.QI60 , Script.Quest.QI108

def GetQuestReward():
  return Script.Quest.QR23 , Script.Quest.QR26 , Script.Quest.QR30 , Script.Quest.QR33 , Script.Quest.QR46 , Script.Quest.QR59 , Script.Quest.QR107


def Talk( player ):
# print "talk to Sparta_009"
  return "Sparta_009"

