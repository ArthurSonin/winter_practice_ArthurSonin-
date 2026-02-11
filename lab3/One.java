import java.util.ArrayList;
import java.util.List;

interface OrderItem {
    double getPrice();
    void showDetails();
}

// ==========================================
// 1. ПАТЕРН BUILDER (Будівельник)
// Допомагає створювати складні об'єкти (Бургер)
// ==========================================
class Burger implements OrderItem {
    private String bun = "Звичайна";
    private String meat = "Яловичина";
    private boolean cheese = false;

    // Сеттери для будівельника
    public void setBun(String bun) { this.bun = bun; }
    public void setMeat(String meat) { this.meat = meat; }
    public void setCheese(boolean cheese) { this.cheese = cheese; }

    @Override
    public double getPrice() { 
        return 100.0 + (cheese ? 20.0 : 0); 
    }

    @Override
    public void showDetails() {
        System.out.println("- Бургер [Булочка: " + bun + ", М'ясо: " + meat + (cheese ? ", +Сир" : "") + "]");
    }
}

class BurgerBuilder {
    private final Burger burger = new Burger();

    public BurgerBuilder withWheatBun() {
        burger.setBun("Пшенична");
        return this;
    }

    public BurgerBuilder addCheese() {
        burger.setCheese(true);
        return this;
    }

    public Burger build() {
        return burger;
    }
}

// ==========================================
// 2. ПАТЕРН COMPOSITE (Компонувальник)
// Дозволяє трактувати окремі страви та набори однаково
// ==========================================


class ComboMeal implements OrderItem {
    private final  String name;
    private final List<OrderItem> items = new ArrayList<>();

    public ComboMeal(String name) { this.name = name; }

    public void addItem(OrderItem item) { items.add(item); }

    @Override
    public double getPrice() {
        return items.stream().mapToDouble(OrderItem::getPrice).sum();
    }

    @Override
    public void showDetails() {
        System.out.println("Набiр: " + name);
        for (OrderItem item : items) {
            item.showDetails();
        }
    }
}

// ==========================================
// 3. ПАТЕРН CHAIN OF RESPONSIBILITY (Ланцюжок обов'язків)
// Обробляє систему знижок по черзі
// ==========================================
abstract class DiscountHandler {
    protected DiscountHandler next;

    public void setNext(DiscountHandler next) {
        this.next = next;
    }

    public abstract double calculate(double price);
}

class StudentDiscount extends DiscountHandler {
    @Override
    public double calculate(double price) {
        System.out.println("-> Застосовано студентську знижку (10%)");
        double newPrice = price * 0.9;
        return (next != null) ? next.calculate(newPrice) : newPrice;
    }
}

class LargeOrderDiscount extends DiscountHandler {
    @Override
    public double calculate(double price) {
        if (price > 200) {
            System.out.println("-> Застосовано знижку за велике замовлення (-30 грн)");
            price -= 30;
        }
        return (next != null) ? next.calculate(price) : price;
    }
}

public class One {
    public static void main(String[] args) {
        System.out.println("=== Створення замовлення (Builder) ===");
        // Створюємо кастомний бургер через Builder
        Burger customBurger = new BurgerBuilder()
                .withWheatBun()
                .addCheese()
                .build();

        System.out.println("=== Формування меню (Composite) ===");
        // Створюємо комбо-набір через Composite
        ComboMeal myCombo = new ComboMeal("Обiд Студента");
        myCombo.addItem(customBurger);
        
        // Додамо простий напій (як окремий елемент)
        myCombo.addItem(new OrderItem() {
            @Override
            public double getPrice() { return 45.0; }
            @Override
            public void showDetails() { System.out.println("- Напiй: Coca-Cola"); }
        });

        myCombo.showDetails();
        double totalPrice = myCombo.getPrice();
        System.out.println("Загальна вартiсть без знижок: " + totalPrice + " грн");

        System.out.println("\n=== Розрахунок знижок (Chain of Responsibility) ===");
        // Налаштовуємо ланцюжок знижок
        DiscountHandler student = new StudentDiscount();
        DiscountHandler largeOrder = new LargeOrderDiscount();
        student.setNext(largeOrder);

        double finalPrice = student.calculate(totalPrice);
        System.out.println("Пiдсумкова цiна: " + finalPrice + " грн");
    }
}