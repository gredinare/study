import scala.collection.mutable.HashMap
object main {
    def main(args: Array[String]) = {
        var a = lengthOfLongestSubstring(" ")
    }

    def lengthOfLongestSubstring(s: String): Int = {
        val stringLen = s.length()
        var maxSubstring = 0
        
        for (start <- 0 until stringLen) {
            var end = start

            val digits_map = new HashMap[Char, Int]()
            var tempMax = 0

            while (end < stringLen) {
                val digit = s.charAt(end)
                val has_digit_in_map = digits_map.get(digit).isDefined

                if (has_digit_in_map) {
                    end += stringLen
                } else {
                    digits_map += digit -> end
                    tempMax += 1
                }

                end += 1
            }
            
            if (tempMax > maxSubstring) {
                maxSubstring = tempMax
            }
        }
        
        println(maxSubstring)
        maxSubstring
    }
}


            // var end = start
            // var repeatChar = false
            // var tempMax = 0

            // while (end < stringLen || repeatChar) {

            //     val digit = s.charAt(end)
            //     val has_digit_in_map = digits_map.get(digit).isDefined

            //     if (has_digit_in_map) {
            //         repeatChar = true
            //     } else {
            //         digits_map += digit -> end
            //         tempMax += 1
            //     }

            //     end += 1;
            // }

            // if (tempMax > maxSubstring) {
            //     maxSubstring = tempMax
            // }