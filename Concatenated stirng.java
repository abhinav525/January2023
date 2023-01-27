class Solution {
    HashSet<String> set;
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res= new ArrayList<>();
        if(words.length==0) return res;
        set = new HashSet<>();
        for(String word : words){
            set.add(word);

        }
        for(String word: words){
            if(isConcat(word)) res.add(word);
        }
        return res;

        
    }
    private boolean isConcat(String word){

        int len = word.length();
        for(int i=1;i<len;i++){
            String suffix= word.substring(i);
            if(set.contains(word.substring(0,i)) && (set.contains(suffix) || isConcat(suffix)))
            return true;

        }
        return false;
    }
}
