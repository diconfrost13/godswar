import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)


def GetQuestReward():
  return Script.Quest.QR171


def Talk( player ):
# print "talk to Parnitha_1_021"
  return "Parnitha_1_021"

