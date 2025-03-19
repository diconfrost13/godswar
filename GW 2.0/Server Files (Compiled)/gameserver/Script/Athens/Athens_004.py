import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1019 , Script.Quest.QI1022

def GetQuestReward():
  return Script.Quest.QR1018 , Script.Quest.QR1021


def Talk( player ):
# print "talk to Athens_004"
  return "Athens_004"

