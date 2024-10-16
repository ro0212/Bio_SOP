#include "a.cpp"
#include "spacer_code.cpp"
#include "analysis.cpp"
#include "promoter_code.cpp"
using namespace std;

int main()
{

    string A;
    string B;
    cout << "Enter first Cis-element" << endl;
    cin >> A;
    cout << "Enter second Cis-element" << endl;
    cin >> B;
    // ------------------------------------------------------------------------------------------
    cout << "Enter Number of chromosomes in the genome " << endl;
    int chromosome_num;
    cin >> chromosome_num;
   
    cout << "Enter name of Folder Name containing chromosome data" << endl;
    string foldername;
    cin >> foldername;
    bool AnalysisType;
    

    ofstream outputFile("promoter.txt");
    string genomeSequence;
    string line;
    vector<string> promoter;
    //-----------------------
    vector<string> genomeSpacers;        // Normal Orientation
    vector<string> genomeSpacersReverse; // Reverse Orientation
    //--------------------
    for (int i = 1; i <= chromosome_num; i++)
    {
        string filename = "/Users/rohitpagar/Desktop/SOP_BIO/Data/" + foldername + "/chr" + to_string(i) + ".fasta";
        ifstream inputFile(filename);
        while (getline(inputFile, line))
        {
            if (line.empty() || line[0] == '>')
            {
                // To skip empty lines;
                continue;
            }
           
           
            genomeSequence += line;
        }
         int CountGenomeSpacers = 0;
         findSpacers(genomeSequence, genomeSpacers, CountGenomeSpacers, A, B);
        inputFile.close();
         
        
        printf("Number of Genome Spacers in chromosome %d: %ld\n",i, genomeSpacers.size());
        //findSpacers(genomeSequence, genomeSpacersReverse, CountGenomeSpacers, B, A);

        cout << "Number of bases in chromosome " + to_string(i) + " : " << genomeSequence.size() << " Nucleotides" << endl;
        genomeSequence.clear();
    }

    //----------------------------------------------------------------------------------------------

   
   

    printf("GenomeSpacers Len: %ld\n", genomeSpacers.size());
    // -----------------------------------

   

    ofstream output("final_output.txt");
   
    ofstream SpacerGenomeData("SpacerGenomeData.txt");
    ofstream NtGenomeData("NtGenomeData.txt");
    helper(genomeSpacers, output, NtGenomeData, SpacerGenomeData, A, B, 1);
    if (A != B)
    {
        helper(genomeSpacersReverse, output, NtGenomeData, SpacerGenomeData, B, A, 2);
    }
    // -----------------------------------------
   
    ofstream ott("data.txt");
    ofstream sp_data("spacer_data.txt");


    
    output.close();
    cout << "Check Output File for Results :) " << endl
         << endl;
    return 0;
}
