import java.util.*;

public class zadanie2 {
    static class Meeting {
        int start;
        int end;
        int id;
        Meeting(int start, int end, int id){
            this.start = start;
            this.end = end;
            this.id = id;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Введите количество встреч: ");
        
        if (!sc.hasNextInt()) {
            sc.close();
            return; 
        }
        
        int n = sc.nextInt();
        
        System.out.println("Введите время начала и окончания каждой встречи (формат: start end): ");
        List<Meeting> meetings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            meetings.add(new Meeting(start, end, i + 1)); 
        }

        meetings.sort(Comparator.comparingInt(m -> m.end));

        List<Integer> result = new ArrayList<>();
        int lastEnd = -1;

        for (Meeting m : meetings){
            if (m.start >= lastEnd){
                result.add(m.id);
                lastEnd = m.end;
            }
        }

        System.out.println("Количество выбранных встреч: " + result.size());
        System.out.print("Номера выбранных встреч: ");
        for (int id : result) {
            System.out.print(id + " ");
        }
        System.out.println(); 
        
        sc.close();
    } 
}