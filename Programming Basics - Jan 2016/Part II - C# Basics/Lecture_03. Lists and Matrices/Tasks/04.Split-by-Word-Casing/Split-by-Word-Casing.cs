using System;
using System.Collections.Generic;
using System.Linq;

public class SplitByWordCasing
{
    /*
     * Split by Word Casing
     *
     * Read a text, split it into words and distribute them into 3 lists:
     *   - Lower-case words, Mixed-case words, Upper-case words.
     *   - Use the following separators: , ; : . ! ( ) " ' / \ [ ] space
     */
    private static void Main(string[] args)
    {
        char[] separators = ",;:.!()\"'/\\[] ".ToArray();

        string[] words = Console.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);

        List<string> lowerCaseWords = new List<string>();
        List<string> mixedCaseWords = new List<string>();
        List<string> upperCaseWords = new List<string>();

        foreach (var word in words)
        {
            var lowerCaseLetters = 0;
            var upperCaseLetters = 0;

            foreach (var letter in word)
            {
                if (char.IsLower(letter))
                {
                    lowerCaseLetters++;
                }
                else if (char.IsUpper(letter))
                {
                    upperCaseLetters++;
                }
            }

            if (lowerCaseLetters == word.Length)
            {
                lowerCaseWords.Add(word);
            }
            else if (upperCaseLetters == word.Length)
            {
                upperCaseWords.Add(word);
            }
            else
            {
                mixedCaseWords.Add(word);
            }
        }

        Console.WriteLine("Lower-case: {0}", string.Join(", ", lowerCaseWords));
        Console.WriteLine("Mixed-case: {0}", string.Join(", ", mixedCaseWords));
        Console.WriteLine("Upper-case: {0}", string.Join(", ", upperCaseWords));
    }
}