import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1018 , Script.Quest.QI1020 , Script.Quest.QI1021

def GetQuestReward():
  return Script.Quest.QR1017 , Script.Quest.QR1019 , Script.Quest.QR1020


def Talk( player ):
# print "talk to Athens_003"
  return "Athens_003"

