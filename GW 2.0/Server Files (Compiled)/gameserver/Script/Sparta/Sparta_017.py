import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI135 , Script.Quest.QI137 , Script.Quest.QI138 , Script.Quest.QI139

def GetQuestReward():
  return Script.Quest.QR137 , Script.Quest.QR138


def Talk( player ):
# print "talk to Sparta_017"
  return "Sparta_017"

