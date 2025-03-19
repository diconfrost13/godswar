import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI85 , Script.Quest.QI89 , Script.Quest.QI113 , Script.Quest.QI162 , Script.Quest.QI163 , Script.Quest.QI170

def GetQuestReward():
  return Script.Quest.QR84 , Script.Quest.QR88 , Script.Quest.QR162 , Script.Quest.QR163 , Script.Quest.QR170


def Talk( player ):
# print "talk to Argolis_All_003"
  return "Argolis_All_003"

